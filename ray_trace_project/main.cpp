#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "Vec3.h"
#include "ImagePNM.h"

using namespace std;

#define IMG_HEIGHT 200
#define IMG_WIDTH 200

struct Ray
{
	Vec3 rayOrigin;
	Vec3 rayEnd;
};

struct Ortho
{
	float xi, xf;
	float yi, yf;
};

struct Pixel
{
	float r, g, b;
};

typedef Pixel Color;

struct Sphere
{
	float xc, yc, zc;
	float ray;

	Color color;

	float ka, kd, ks, n;
};


bool sphereInterception(Ray ray, Sphere sphere, Vec3 &pi, Vec3 n, Color &color) {
	float A, B, C;

	Vec3 rayOrigin = ray.rayOrigin;
	Vec3 rayEnd = ray.rayEnd;

	A = 1;

	B = 2 * (rayEnd.x * (rayOrigin.x - sphere.xc) + rayEnd.y * (rayOrigin.y - sphere.yc) + rayEnd.z * (rayOrigin.z - sphere.zc));
	C = (rayOrigin.x - sphere.xc)* (rayOrigin.x - sphere.xc) + (rayOrigin.y - sphere.yc) * (rayOrigin.y - sphere.yc) + (rayOrigin.z - sphere.zc) * (rayOrigin.z - sphere.zc) - sphere.ray * sphere.ray;

	float t, t0, t1;
	float delta;
	
	//(slide 28)
	delta = B * B - 4 * A * C;

	//If delta > 0, then sphere is not hit
	if (delta < 0)
		return false;
	//If delta = 0 then we have intersection (Baskhara to find t)
	else if (delta == 0)
	{
		t = -B / 2 * A;
	}
	//If delta > 0, then we have 2 results, then calculate both and return the smallest positive result as t
	else {

		t0 = -B - sqrt(delta) / 2 * A;
		t1 = -B + sqrt(delta) / 2 * A;

		/*cout << "t0 = " << t0 << endl;
		cout << "t1 = " << t1 << endl;*/

		if ((t0, t1) == t0)
		{
			t = t0;
		}
		else
		{
			t = t1;
		}
	}

	// (slide 29)
	pi.x = rayOrigin.x + t * rayEnd.x;
	pi.y = rayOrigin.y + t * rayEnd.y;
	pi.z = rayOrigin.z + t * rayEnd.z;

	//cout << "Pi(xi,yi,zi) = (" << pi.x << "," << pi.y << "," << pi.z << ")" << endl; 

	//(slide 29)
	n.x = (pi.x - sphere.xc) / sphere.ray;
	n.y = (pi.y - sphere.yc) / sphere.ray;
	n.z = (pi.z - sphere.zc) / sphere.ray;

	color = sphere.color;

	return true;
}

int main() {

	//Defines virtual observer
	Vec3 eye;
	eye.x = 0;
	eye.y = 0;
	eye.z = 50.0; // observe in positive z

	//Defines world window
	Ortho ortho;
	ortho.xi = -10.0;
	ortho.xf = 10.0;
	ortho.yi = -10.0;
	ortho.yf = 10.0;

	//Image Resolution
	float width = IMG_WIDTH, height = IMG_HEIGHT;
	ImagePNM imagePNM;
	Image *pixels = new Image(width, height);

	//Percorre a grid
	float cellX = (ortho.xf - ortho.xi) / width;
	float cellY = (ortho.yf - ortho.yi) / height;

	
	vector <Sphere> spheres(3);

	//Esfera 1
	spheres[0].xc = 0;
	spheres[0].yc = 0;
	spheres[0].zc = -2;
	spheres[0].ray = 1;

	Color sphereColor;
	sphereColor.r = 255;
	sphereColor.g = 0;
	sphereColor.b = 0;

	spheres[0].color = sphereColor;


	//Esfera 2
	spheres[1].xc = -7;
	spheres[1].yc = 0;
	spheres[1].zc = -1;
	spheres[1].ray = 2;

	sphereColor.r = 0;
	sphereColor.g = 0;
	sphereColor.b = 255;

	spheres[1].color = sphereColor;


	//Esfera 3
	spheres[2].xc = 5;
	spheres[2].yc = 0;
	spheres[2].zc = -2;
	spheres[2].ray = 2.5;

	sphereColor.r = 0;
	sphereColor.g = 255;
	sphereColor.b = 0;

	spheres[2].color = sphereColor;




	system("pause");
	return 0;
}