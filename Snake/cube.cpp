/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#include "cube.h"

namespace Models {
	namespace CubeInternal {
			unsigned int vertexCount=36;

			float vertices[]={
				1.0f,-1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				-1.0f,-1.0f,-1.0f,1.0f,

				1.0f,-1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,


				-1.0f,-1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,

				-1.0f,-1.0f, 1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,

				1.0f,-1.0f, 1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				1.0f,-1.0f,-1.0f,1.0f,

				1.0f,-1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,
				1.0f,-1.0f,-1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,

				-1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,

				-1.0f, 1.0f, 1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,

			};

			float colors1[]={
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,

				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
				0.5f,0.5f,0.5f,1.0f,
			};

			float colors2[] = {
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,

				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
				0.86f,0.86f,0.86f,1.0f,
			};

			float normals[]={
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
			};

			float vertexNormals[]={
				1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,


				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
			};

			float texCoords[]={
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,
			};
	}
}
