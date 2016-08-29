#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public :
		enum Mode{RECT,POL};
		//RECT for rectangle,POL for Polar modes
	private:
		double x;		//horizontal value
		double y;		//vertical value
		double mag;		//length of vector
		double ang;		//director of value in degrees
		Mode mode;		//RECT or POL

		//private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xvalue()const { return x; }
		double yvalue()const { return y; }
		double magvalue()const { return mag; }
		double angvalue()const { return ang; }
		void polar_mode();		//set mode to POL
		void rect_mode();		//ser mode to RECT
		//operator overloding
		Vector operator+(const Vector &b)const;
		Vector operator-(const Vector &b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		//friends
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream &
			operator <<(std::ostream &os, const Vector &v);
	};
}//end namespace VECTOR

#endif // !VECTOR_H_

