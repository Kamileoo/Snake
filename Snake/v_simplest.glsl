#version 330

//Zmienne jednorodne
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
uniform vec4 lp;
uniform vec4 lp2;

//Atrybuty
in vec4 vertex; //wspolrzedne wierzcholka w przestrzeni modelu
in vec4 color; //kolor związany z wierzchołkiem
in vec4 normal; //wektor normalny w przestrzeni modelu

//Zmienne interpolowane
out vec4 ic;
out vec4 l;
out vec4 l2;
out vec4 n;
out vec4 v;

void main(void) {
    vec4 lp = vec4(16, 10, -6, 1); //pozcyja światła, przestrzeń świata
    vec4 lp2 = vec4(-10, 8, 40, 1); //pozcyja światła, przestrzeń świata
    l = normalize(V * lp - V*M*vertex); //wektor do światła w przestrzeni oka
    l2 = normalize(V * lp2 - V * M * vertex); //wektor do światła w przestrzeni oka
    v = normalize(vec4(0, 0, 0, 1) - V * M * vertex); //wektor do obserwatora w przestrzeni oka
    n = normalize(V * M * normal); //wektor normalny w przestrzeni oka
    
    ic = color;
    
    gl_Position=P*V*M*vertex;
}