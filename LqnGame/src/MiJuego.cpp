#include "..\includes\MiJuego.h"
bool MiJuego::OnInit() {

	cuadradito = new Quad(&graphics);
	cuadradito->xPos = 500.0f;
	cuadradito->yPos = 500.0f;
	sprite = new Sprite(&graphics);
	sprite->setTexture(L"C:\\Users\\Sebastianote\\Pictures\\prueba.png");
	cuadradito2 = new Quad(&graphics);

	cuadradito2->xPos = -500.0f;
	return true; 
}
bool MiJuego::OnUpdate() {
	return true;
}
void MiJuego::OnDraw() {
	cuadradito->Draw();
	sprite->Draw();
	cuadradito2->Draw();
}
bool MiJuego::OnShutDown() {
	return true;
}