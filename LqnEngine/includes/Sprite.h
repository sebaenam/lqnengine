#ifndef SPRITE_H
#define SPRITE_H
using namespace std;

#include "VertexUV.h"
#include "Entity2D.h"
#include <string>

class LQN_API Sprite : public Entity2D {
	VertexUV *vertex;
	string texturePath;
	IDirect3DTexture9* m_texture = 0;
public:
	Sprite(Graphics *graphics) : Entity2D(graphics) {
		vertex = new VertexUV[4];
		vertex[0] = { -200.0f, 200.0f, 0.5f, 0.0f, 0.0f };
		vertex[1] = { -200.0f, -200.0f, 0.5f, 0.0f, 1.0f };
		vertex[2] = { 200.0f, 200.0f, 0.5f, 1.0f, 0.0f };
		vertex[3] = { 200.0f, -200.0f, 0.5f, 1.0f, 1.0f };
	}
	void Draw() {
		Entity2D::graphics->BindTexture(m_texture);
		Entity2D::Draw();
		Entity2D::graphics->DrawSprite(vertex, D3DPT_TRIANGLESTRIP, 4, m_texture);
	}
	void setTexture(LPCWSTR texturePath) {
		m_texture = graphics->LoadTexture(texturePath);
	}
	void setTextureZone(float offSetX,float offSetY,float tileWidth,float tileHeight) {
		D3DSURFACE_DESC desc;
		float textWidth = m_texture->GetLevelDesc(0,&desc);
		vertex[0].setUV(offSetX/desc.Width, offSetY/desc.Height);
		vertex[1].setUV(offSetX/desc.Width, (offSetY+ tileHeight)/desc.Height);
		vertex[2].setUV((offSetX+ tileWidth)/desc.Width, offSetY/desc.Height);
		vertex[3].setUV((offSetX+ tileWidth)/desc.Width, (offSetY+ tileHeight)/desc.Height);
	}
};



#endif