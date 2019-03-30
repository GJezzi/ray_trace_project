#include "Vec3.h"

/* DOT - This routine computes the dot product of two vec3s */
float dot(Vec3 &v1, Vec3 &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/*SVMPY - This routine multiples a vec3 by a constant*/
Vec3 svmpy(float s, Vec3 &v) {
	Vec3  result;
	result.x = s * v.x;
	result.y = s * v.y;
	result.z = s * v.z;

	return result;
}// End svmpy

/* NORMALIZE - This routine normalizes the given vec3 */
Vec3 normalize(Vec3 v) {

	float denom; // Temporary denominator

	float x = v.x;
	float y = v.y;
	float z = v.z;;

	float norm = sqrt(x*x + y * y + z * z);
	Vec3 aux(float(x / norm), float(y / norm), float(z / norm));
	return aux;

}// End procedure normalize

/*VADD -  This routine adds two vec3s*/
Vec3 vadd(Vec3 &v1, Vec3 &v2) {
	Vec3  result(v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z);
	return result;
} // End vadd

/*VSUB -  This routine subtracts two vec3s*/
Vec3 vsub(Vec3 &v1, Vec3 &v2) {
	Vec3 result(v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z);
	return result;
}// End vsub

/*VPROD - This routine computes the vec3ial product of two vec3s*/
Vec3 vprod(Vec3 &v1, Vec3 &v2) {
	Vec3 result(v1.y*v2.z - v1.z*v2.y,
		v1.z*v2.x - v1.x*v2.z,
		v1.x*v2.y - v1.y*v2.x);
	return result;
}// End vprod
