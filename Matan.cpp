#include <iostream>
#include <iomanip>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

class POINT
{
private:
    int x;
    int y;
public:
    POINT()
    {
        x = 0;
        y = 0;
    };
    POINT(int ux, int uy) 
    {
        setXY(ux, uy);
    }
    void setXY(int ux, int uy)
    {
        x = ux;
        y = uy;
    }
    void getXY()
    {
        cout << x << setw(5) << y<<endl;
    }
    double c_distXoY()
    {
        cout << sqrt(pow(x, 2) + pow(y, 2)) << endl;
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    double distXoY()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
protected:

};

class LINE : public POINT
{
private:
    POINT A, B;
public:
    LINE()
    {}
    LINE(int ux, int uy)
    {
        A.setXY(0, 0);
        B.setXY(ux, uy);
    }
    LINE(int a_ux, int a_uy, int b_ux, int b_uy)
    {
        A.setXY(a_ux, a_uy);
        B.setXY(b_ux, b_uy);
    }
    double dist()
    {
        return sqrt(pow(abs(A.getX() - B.getX()), 2)+ pow(abs(A.getY() - B.getY()), 2));
    }
    double c_dist()
    {
        cout << sqrt(pow(abs(A.getX() - B.getX()), 2) + pow(abs(A.getY() - B.getY()), 2)) << endl;
        return sqrt(pow(abs(A.getX() - B.getX()), 2) + pow(abs(A.getY() - B.getY()), 2));
    }
    void getAB()
    {
        cout << "A" << setw(8) << " |"; A.getXY();
        cout << "B" << setw(8) << " |"; B.getXY();
    }
};

class SQUARE : public LINE
{
private:
    POINT A;
    POINT B;
    POINT C;
    POINT D;
public:
    void create_line()
    {
        LINE AB(A.getX(), A.getY(), B.getX(), B.getY());
        LINE BC(B.getX(), B.getY(), C.getX(), C.getY());
        LINE CD(C.getX(), C.getY(), D.getX(), D.getY());
        LINE DA(D.getX(), D.getY(), A.getX(), A.getY());
    }
    double p()
    {
        LINE AB(A.getX(), A.getY(), B.getX(), B.getY());
        LINE BC(B.getX(), B.getY(), C.getX(), C.getY());
        LINE CD(C.getX(), C.getY(), D.getX(), D.getY());
        LINE DA(D.getX(), D.getY(), A.getX(), A.getY());
        return (AB.dist() + BC.dist() + CD.dist() + DA.dist())/2;
    }
    SQUARE(int a_ux, int a_uy, int b_ux, int b_uy, int c_ux, int c_uy, int d_ux, int d_uy)
    {
        create_line();
    }
    double S()
    {
        LINE AB(A.getX(), A.getY(), B.getX(), B.getY());
        LINE BC(B.getX(), B.getY(), C.getX(), C.getY());
        LINE CD(C.getX(), C.getY(), D.getX(), D.getY());
        LINE DA(D.getX(), D.getY(), A.getX(), A.getY());
        return sqrt((p()-AB.dist())*(p() - BC.dist())*(p() - CD.dist())*(p() - DA.dist()));
    }
    double c_S()
    {
        LINE AB(A.getX(), A.getY(), B.getX(), B.getY());
        LINE BC(B.getX(), B.getY(), C.getX(), C.getY());
        LINE CD(C.getX(), C.getY(), D.getX(), D.getY());
        LINE DA(D.getX(), D.getY(), A.getX(), A.getY());
        cout << sqrt((p() - AB.dist()) * (p() - BC.dist()) * (p() - CD.dist()) * (p() - DA.dist())) << endl;
        return sqrt((p() - AB.dist()) * (p() - BC.dist()) * (p() - CD.dist()) * (p() - DA.dist()));
    }
};

int main()
{
    POINT P1; P1.setXY(4, 8);
    POINT P2(1, 3);
    POINT P3(3, 5);
    POINT P4(7, 1);
    LINE L1(P1.getX(), P1.getY(), P2.getX(), P2.getY());
    SQUARE SQ(P1.getX(), P1.getY(), P2.getX(), P2.getY(), P3.getX(), P3.getY(), P4.getX(), P4.getY());
    cout << setw(10) << 'x' << setw(5) << 'y' << endl;
    cout << "POINT_1 |"; P1.getXY();
    cout << "POINT_2 |"; P2.getXY();
    L1.getAB();
    L1.c_dist();
    SQ.c_S();
}
