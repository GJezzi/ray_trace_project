#include "ImagePNM.h"
#include <iostream>
#include <fstream>

#define BUFF_SIZE 500

using namespace std;

void ImagePNM::readPNM(char *fileName) {
	cout << "Reading image " << fileName << "\n";

	ifstream input(fileName, ios::in);
	if (!input)
	{
		cerr << "File " << fileName << " couldn´t be opened!\n";
		exit(1);
	}

	char buffer[BUFF_SIZE];
	input.getline(buffer, BUFF_SIZE);
	input.getline(buffer, BUFF_SIZE);
	
	input >> width;
	input >> height;
	cout << "Resolution " << width << "X" << height << "Y\n";

	image = new Image(width, height);

	int max;
	input >> max;

	int x = 0;
	int y = height;

	for (int y = height - 1; y >= 0; y--)
		for (int x = 0; x < width; x++)
		{
			int r, g, b, a;
			input >> r;
			input >> g;
			input >> b;
			cout << r << " " << g << " " << b << "\n";

			if (r == 255 && g == 0 && b == 255)
				a = 0;
			else a = 255;
			int rgb = (a << 24) | (b << 16) | (g << 8) | r;
			//int rgb = (a << 24) | (r << 16) | (g << 8) | b;
			image->setRGB(x, y, rgb);
		}
	cout << "Successful file reading. \n";
}

void ImagePNM::createPNM(char *fileName) {
	ofstream file(fileName, ios::out | ios::binary);

	file << "P3" << endl;
	file << "# " << endl;
	file << width << " " << height << endl;
	file << 255 << endl;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < height; j++) {
			int pixel = image->getRGB(j, i);
			int b = (pixel >> 16) & 255;
			int g = (pixel >> 8) & 255;
			int r = (pixel) & 255;
			file << r << " " << g << " " << b << "\n";
		}
	file.close();
}
