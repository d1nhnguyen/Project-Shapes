#include"myFunctions.h"

int main() {
    void** shapes = new void*[Max];
	Type* types = new Type[Max];
    int cnt = 0;

	/*Doc file input*/
    ifstream reader;
	reader.open("input.txt", ios::in);
	string n_temp;
	getline(reader, n_temp);
	int n = stoi(n_temp);
	if (reader.good()) { 
		for (int i = 0; i < n; i++){
			string buffer;
			getline(reader, buffer);
			shapes[i] = returnShapes(buffer, types[i]);
			cnt++;
		}
	
		reader.close();
	}
	
	/*Xuat cac hinh da doc*/
	output(shapes, types, n);
	cout << endl;
	
	/*Tim cac hinh co chu vi, dien tich nho nhat va lon nhat*/
	int maxArea = maxAreaIndex(shapes, types, n);
	int minArea = minAreaIndex(shapes, types, n);
	int maxPerimeter = maxPerimeterIndex(shapes, types, n);
	int minPerimeter = minPerimeterIndex(shapes, types, n);
	
	cout << "Hinh co dien tich lon nhat la: "; printAreaOnly(shapes[maxArea], types[maxArea]);
	cout << "Hinh co chu vi lon nhat la: "; printPerimeterOnly(shapes[maxPerimeter], types[maxPerimeter]);
	cout << "Hinh co dien tich nho nhat la: "; printAreaOnly(shapes[minArea], types[minArea]);
	cout << "Hinh co chu vi nho nhat la: "; printPerimeterOnly(shapes[minPerimeter], types[minPerimeter]);
	cout << endl;
	
	/*Thong ke so luong cac loai hinh da doc*/
	int countSquare = 0, countRectangle = 0, countCircle = 0;
	countShapes(countSquare, countRectangle, countCircle, types, n);
	cout << "Thong ke so luong cac hinh da doc: " << endl;
	cout << "+ Square: " << countSquare << endl;
	cout << "+ Circle: " << countCircle << endl;
	cout << "+ Rectangle: " << countRectangle << endl;
	
	
    for (int i = 0; i < cnt; ++i) {
        if (types[i] == Type::SQUARE) {
            delete static_cast<Square*>(shapes[i]);
        } else if (types[i] == Type::RECTANGLE) {
            delete static_cast<Rectangle*>(shapes[i]);
        } else if (types[i] == Type::CIRCLE) {
            delete static_cast<Circle*>(shapes[i]);
        }
    }
	delete[] shapes;
	delete[] types;
    return 0;
}
