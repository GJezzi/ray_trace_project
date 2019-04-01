#include "Image.h"
#include <cstdio>

class ImagePNM
{
public:
	ImagePNM() { image = NULL; width = 0 ; height = 0; };
	~ImagePNM() {}

	void readPNM(char *fileName);
	void createPNM(char *fileName);

	Image *returnImage() { return image; }
	void receiveImage(Image *img) {
		image = img;
		width = img->getWidth();
		height = img->getHeight();
	}

	int returnWidth() { return width; }
	int returnHeight() { return height; }

private:
	Image *image;
	int width;
	int height;
};

