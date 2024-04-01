#include <iostream> 
#include <graphic.h> 
using namespace std;


{
    Initgraph();
}
class Rectangle {
    int width, height;

    public: 
        void set_values (int,int);

        int area() {
            return width * height;
        }
};

void Rectangle::set_values(int x, int y)
{
    width = x;
    height = y;

}
/*
int main()
{
    Rectangle rect;

    rect.set_values(3,4);

    cout << "area: " << rect.area();

    return 0;
}*/
/*
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "");
line(140, 140, 350, 100);
line(140, 140, 200, 200);
line(350, 140, 200, 200);
getch();
closegraph();
}
*/
