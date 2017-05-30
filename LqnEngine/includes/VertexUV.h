#ifndef VERTEXUV_H
#define VERTEXUV_H
using namespace std;

#include "ImportExport.h"
#include <d3d9.h>

struct LQN_API VertexUV {
	FLOAT x, y, z;
	FLOAT u, v;
	//DWORD color = D3DCOLOR_ARGB(0, 0, 0, 0);    // from the D3DFVF_DIFFUSE flag
	static const DWORD fvf = D3DFVF_XYZ | D3DFVF_TEX1 /*| D3DFVF_DIFFUSE*/;

public :
	VertexUV() {}
	VertexUV(float rX, float rY, float rZ, float rU, float rV) {
		x = rX;
		y = rY;
		z = rZ;
		u = rU;
		v = rV;
	}

	void setCoordinates(float rX, float rY, float rZ) {
		x = rX;
		y = rY;
		z = rZ;
	}

	void setUV(float rU, float rV) {
		u = rU;
		v = rV;
	}
};

#endif