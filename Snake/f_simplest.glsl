#version 330


out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

in vec4 ic; 
in vec4 n;
in vec4 l;
in vec4 l2;
in vec4 v;

void main(void) {

	//Znormalizowane interpolowane wektory
	vec4 ml = normalize(l);
	vec4 ml2 = normalize(l2);
	vec4 mn = normalize(n);
	vec4 mv = normalize(v);
	//Wektor odbity
	vec4 mr = reflect(-ml, mn);
	vec4 mr2 = reflect(-ml2, mn);

	//Parametry powierzchni
	vec4 kd = ic;
	vec4 ks = vec4(1, 1, 1, 1);

	//Obliczenie modelu oświetlenia
	float nl = clamp(dot(mn, ml), 0, 1);
	float nl2 = clamp(dot(mn, ml2), 0, 1);
	float nlF = nl + nl2;
	float rv = pow(clamp(dot(mr, mv), 0, 1), 50);
	float rv2 = pow(clamp(dot(mr2, mv), 0, 1), 50);
	float rvF = rv + rv2;
	//pixelColor = vec4(kd.rgb * nl, kd.a) + vec4(ks.rgb * rv, 0);
	pixelColor = vec4(kd.rgb * nlF, kd.a) + vec4(ks.rgb * rvF, 0);
}
