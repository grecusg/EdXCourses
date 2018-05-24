// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <stdio.h>

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	vec3 u, v, w;
	mat3 R, AStar, aaT;
	mat3 I(1.0);
	float cosTheta, sinTheta, x, y, z;

	cosTheta = cos(degrees * pi / 180);
	sinTheta = sin(degrees * pi / 180);
	x = axis[0];
	y = axis[1];
	z = axis[2];

	AStar = mat3(0, z, -y, -z, 0, x, y, -x, 0);
	aaT = mat3(x*x, x*y, x*z, x*y, y*y, y*z, x*z, y*z, z*z);

	R = cosTheta * I + (1.0 - cosTheta) * aaT + sinTheta * AStar;
  return R;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	float theta = degrees * pi / 180;
	mat3 Ry = mat3(cos(theta), 0, -sin(theta), 0, 1, 0, sin(theta), 0, cos(theta));
  // YOUR CODE FOR HW1 HERE
	eye = Ry * eye;
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	float theta = -degrees * pi / 180;
	mat3 Rx = mat3(1, 0, 0, 0, cos(theta), sin(theta), 0, -sin(theta), cos(theta));
	eye = Rx * eye;
	up = Rx * up;
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	printf("Up: %.2f, %.2f, %.2f; distance: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
	// Create a coordinate frame for the camera
	vec3 u, v, w;
	mat4 M;

	w = glm::normalize(eye);
	u = glm::normalize(glm::cross(up, w));
	v = glm::cross(w, u);

	// Define a rotation matrix
	//M = mat4(u.x, v.x, w.x, 0, u.y, v.y, w.y, 0, u.z, v.z, w.z, 0, (u.x * ???)

	// Apply translation to eye

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
