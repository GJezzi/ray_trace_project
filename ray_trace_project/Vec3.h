#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

class Vec3
{
public:
	Vec3() {};
	Vec3(float xi, float yi, float zi) {
		x = xi;       y = yi;       z = zi;
	}

	void print() { cout << "(" << x << "," << y << "," << z << ")\n"; }

	void operator=(Vec3 v2) {
		x = v2.x;
		y = v2.y;
		z = v2.z;
	}


	float x;
	float y;
	float z;
};

/* DOT - This routine computes the dot product of two vec3s */
float dot(Vec3 &v1, Vec3 &v2);

/*SVMPY - This routine multiples a vec3 by a constant*/
Vec3 svmpy(float s, Vec3 &v);

/* NORMALIZE - This routine normalizes the given vec3 */
Vec3 normalize(Vec3 v);

/*VADD -  This routine adds two vec3s*/
Vec3 vadd(Vec3 &v1, Vec3 &v2);

/*VSUB -  This routine subtracts two vec3s*/
Vec3 vsub(Vec3 &v1, Vec3 &v2);

/*VPROD - This routine computes the vec3ial product of two vec3s*/
Vec3 vprod(Vec3 &v1, Vec3 &v2);

