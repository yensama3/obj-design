#include<iostream>
#include<cmath>
using namespace std;

class Point{
public:
	int x,y;
	Point(){}
	Point(int a,int b){x=a;y=b;}
	virtual void display()=0; //纯虚函数
};

class Line:public Point{
public:
	Line(int x1=0,int y1=0,int x2=0,int y2=0){m=x2,n=y2;}
	double lineDistance;
	double distance(double x1=0,double y1=0,double x2=0,double y2=0){
		return sqrt((y2- y1)*(y2 - y1)+(x2- x1)*(x2 - x1));
	}
	virtual void display(){};
protected:
	int m;
	int n;
};

class Triangle :public Line{
public:
	void Area(double x1, double y1, double x2, double y2, double x3, double y3);
	virtual void display(){
		cout<<area;	
	};											//纯虚函数的实现
	double area;
};

void Triangle::Area(double x1, double y1, double x2, double y2, double x3, double y3) //面积实现
{
	double x, y, z, p;
	Line l1,l2,l3;
	x = l1.distance(x1,y1,x2,y2);
	y = l2.distance(x2,y2,x3,y3);
	z = l3.distance(x3,y3,x1,y1); 

	p = (x + y + z) / 2;
 	area =  sqrt(p*(p - x)*(p - y)*(p - z));//海伦公式应用
}

int main(){
	double sum;
	Triangle a,b,c;
	a.Area(0,0,3,5,9,8);
	b.Area(2,4,6,7,5,8);
	c.Area(1,2,3,6,9,9);
	cerr<<"a（0，0，3，5，9，8）的面积：";
	a.display();
	cout<<"\nb（2，4，6，7，5，8）的面积:";
	b.display();
	cout<<"\nc（1，2，3，6，9，9）的面积:";
	c.display();
	
	sum = a.area+b.area+c.area;
	cout<<"\na,b,c的面积和为："<<sum<<endl;
}


