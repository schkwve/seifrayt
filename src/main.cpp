#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#include <seif.h>

struct rgb_data {
	double r;
	double g;
	double b;
};

void write_seif(const char *filename, int w, int h, struct rgb_data *data)
{
	FILE *f;

	// fill out SEIF metadata
	SEIF_Meta metadata = {
		.signature = {'S','E','I','F','R','A','Y','T'},
		.width = static_cast<u32>(w),
		.height = static_cast<u32>(h)
	};

	// fill out SEIF header
	SEIF_Header header = {
		.magic = {'S','E','I','F'},
		.flags = 0,
		.encoding = SEIF_ENCODING_RGB,
		.meta = metadata,
		.chunk_count = 1,
		.chunk_size = static_cast<u32>(w*h)
	};

#if defined(DEBUG)
	printf("Debug image info:\n  [HEADER]:\n");
	printf("    - magic: %s\n", header.magic);
	printf("    - flags: 0x%.2x\n", header.flags);
	printf("    - encoding: 0x%.2x\n", header.encoding);
	printf("    - [META]:\n");
	printf("      - signature: %s\n", header.meta.signature);
	printf("      - width: %u\n", header.meta.width);
	printf("      - height: %u\n", header.meta.height);
	printf("    - chunk_count: %u\n", header.chunk_count);
	printf("    - chunk_size: %u\n", header.chunk_size);
#endif

	// open file
	f = fopen(filename, "wb");
	if (f == NULL) {
		fprintf(stderr, "Failed to open '%s': %s!", filename, strerror(errno));
	}

	// write header
	fwrite(&header, 1, sizeof(header), f);

	// write image data
	for (int i = 0; i < w*h; i++) {

		u8 col[3] = {
			(int)data[i].r,
			(int)data[i].g,
			(int)data[i].b
		};

		fwrite(col, 1, 3, f);
	}

	fclose(f);
}

int main(int argc, char *argv[])
{
	int width = 32;
	int height = 32;

	struct rgb_data *data = new struct rgb_data[width*height];

	// generate pure white pixels
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			int k = y*width + x;
			data[k].r = 255;
			data[k].g = 255;
			data[k].b = 255;
		}
	}

	write_seif("output.seif", width, height, data);

	return 0;
}
