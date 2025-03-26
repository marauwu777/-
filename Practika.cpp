#include <iostream>
#include <cmath>
using namespace std;
struct Point {
	double x, y;
};
struct Line {
	double A, B, D;
};
Point FindIntersection(Line line1, Line line2) {
	Point ans;
	double det = line1.A * line2.B - line1.B * line2.A;
	if (det == 0) {
		throw runtime_error("Are the lines parallel or coincide");
	}
	ans.x = (-line1.D * line2.B + line1.B * line2.D) / det;
	ans.y = (-line1.A * line2.D + line1.D * line2.A) / det;
	return ans;
}
int main() {
	Line line1, line2;
	double d;
	cin >> line1.A >> line1.B >> line1.D >> line2.A >> line2.B >> line2.D >> d;
	Point intersection = FindIntersection(line1, line2);
	double A = pow((pow(line2.A, 2) * pow(line1.B, 2) - pow(line1.A, 2) * pow(line2.B, 2) - pow(line2.A, 2) * pow(line1.B, 3) + pow(line1.B, 2) * line1.A * line2.A * line2.B) / (pow(line1.A, 2) * pow(line2.A, 2) * line1.B - pow(line1.A, 3) * line2.A * line2.B), 2) - 2 * ((pow(line2.A, 2) * pow(line1.B, 2) - pow(line1.A, 2) * pow(line2.B, 2) - pow(line2.A, 2) * pow(line1.B, 3) + pow(line1.B, 2) * line1.A * line2.A * line2.B) / (pow(line1.A, 2) * pow(line2.A, 2) * line1.B - pow(line1.A, 3) * line2.A * line2.B) + pow((pow(line1.B, 2) * pow(line2.A, 2) - pow(line2.B, 2) * pow(line1.A, 2)) / (line1.A * pow(line2.A, 2) * line1.B - pow(line1.A, 2) * line2.A * line2.B), 2) + 1);
	cout << A;
}