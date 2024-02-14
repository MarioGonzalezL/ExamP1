#include <iostream>
#include <string>
using namespace std;

class Rectangulo
{
    private:
        int ancho;
        int altura;

    public:
        int esquinaX;
        int esquinaY;

        Rectangulo();
        Rectangulo(int x, int y);
        Rectangulo(int x, int y, int w, int h);

        int getAncho();
        void setAncho(int w);
        int getAltura();
        void setAltura(int h);
        int getArea();
        void intersecta(Rectangulo rect);
};

int main()
{
    Rectangulo ra1;
    ra1.setAncho(7);
    ra1.setAltura(8);
    ra1.esquinaX= 9;
    ra1.esquinaY= 1;

    Rectangulo ra2(2, 3);
    ra2.setAncho(7);
    ra2.setAltura(9);

    Rectangulo ra3(4,1,4,6);

    cout << "Area rectangulo1 "<< ra1.getArea()<< endl;
    cout << "Area rectangulo2 "<< ra2.getArea()<< endl;
    cout << "Area rectangulo3 "<< ra3.getArea()<< endl;

    ra1.intersecta(ra2);
    ra1.intersecta(ra3);
    ra3.intersecta(ra2);


return 0;
}

Rectangulo::Rectangulo()
{
    setAncho(0);
    setAltura(0);
    esquinaX= 0;
    esquinaY= 0;
}

Rectangulo::Rectangulo(int x, int y)
{
    setAncho(0);
    setAltura(0);
    esquinaX= x;
    esquinaY= y;
}

Rectangulo::Rectangulo(int x, int y, int w, int h)
{
    if(w >= 0)
    {
        ancho=w;
    }else{
        ancho = 0;
    }

    if(h >= 0)
    {
        altura=h;
    }else{
        altura = 0;
    }

    esquinaX= x;
    esquinaY= y;
}

int Rectangulo::getAncho()
{
    return ancho;
}

void Rectangulo::setAncho(int w)
{
    ancho = w;
}

int Rectangulo::getAltura()
{
    return altura;

}

void Rectangulo::setAltura(int h)
{
    altura = h;
}

int Rectangulo::getArea()
{
    return ancho * altura;
}

void Rectangulo::intersecta(Rectangulo rect)
{
    bool interseccionX , interseccionY;
    if (esquinaX <= (rect.esquinaX+rect.ancho) && (esquinaX + ancho) >= rect.esquinaX)
    {
        interseccionX = true;
    }else{
        interseccionX = false;
    }
    if (esquinaY <= (rect.esquinaY+rect.altura) && (esquinaY + altura) >= rect.esquinaY)
    {
        interseccionY = true;
    }else{
        interseccionY = false;
    }

    if(interseccionX && interseccionY)
    {
        cout << "Los rectangulos si intersectan" << endl;
    }else{
        cout << "Los rectangulos no intersectan" << endl;
    }
}
