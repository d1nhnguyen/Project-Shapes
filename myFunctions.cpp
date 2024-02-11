#include"myFunctions.h"

/*Ham de luu lai cac hinh vao mang shapes*/
void* returnShapes(string s, Type& type) {
    // Tach loai hinh ra khoi chuoi
    size_t pos = s.find_first_of(":");
    string shape = s.substr(0, pos);

    if (shape == "Square") {
        /*Tach canh*/
        int equalPos = s.find_first_of("=", pos);
        float side = stof(s.substr(equalPos + 1));
        Square* temp = new Square{side, 0, 0};

        temp->area = temp->calculateArea();
        temp->perimeter = temp->calculatePerimeter();
        type = Type::SQUARE;
        return static_cast<void*>(temp);
    } else if (shape == "Circle") {
        /*Tach ban kinh*/
        int radiusPos = s.find_first_of("r", pos);
        float radius = stof(s.substr(radiusPos + 2));

        Circle* temp = new Circle{radius, 0, 0};
        temp->area = temp->calculateArea();
        temp->perimeter = temp->calculatePerimeter();
        type = Type::CIRCLE;
        return static_cast<void*>(temp);
    } else {
        /*Tach chieu dai va chieu rong*/
        int widthPos = s.find_first_of("w", pos);
        int heightPos = s.find_first_of("h", pos);
        float width = stof(s.substr(widthPos + 2, heightPos - widthPos - 2));
        float height = stof(s.substr(heightPos + 2));

        Rectangle* temp = new Rectangle{width, height, 0, 0};
        temp->area = temp->calculateArea();
        temp->perimeter = temp->calculatePerimeter();
        type = Type::RECTANGLE;
        return static_cast<void*>(temp);
    }
}

/*Xu ly phan xuat cac hinh*/

void print(const Square* value) {
    cout << "Square a=" << value->side << " => area=" << value->area << ", perimeter=" << value->perimeter << endl;
}

void print(const Rectangle* value) {
    cout << "Rectangle w=" << value->width << ", h=" << value->height
              << " => area=" << value->area << ", perimeter=" << value->perimeter << endl;
}

void print(const Circle* value) {
    cout << "Circle r=" << value->radius << " => area=" << value->area << ", perimeter=" << value->perimeter << endl;
}

void print(void* value, Type types) {
    switch (types) {
        case Type::SQUARE:
            print(static_cast<Square*>(value));
            break;
        case Type::RECTANGLE:
            print(static_cast<Rectangle*>(value));
            break;
        case Type::CIRCLE:
            print(static_cast<Circle*>(value));
            break;
    }
}


void output(void* shapes[], Type* types, int n){
	for (int i = 0; i < n; i++) {
		print(shapes[i], types[i]);
	}
}

/*Xu ly phan dien tich lon nhat, nho nhat*/
float returnArea(void* value, Type type) { // Ham tra ve gia tri dien tich de so sanh
    switch (type) {
        case Type::SQUARE:
            return static_cast<const Square*>(value)->area;
        case Type::RECTANGLE:
            return static_cast<const Rectangle*>(value)->area;
        case Type::CIRCLE:
            return static_cast<const Circle*>(value)->area;
        default:
            return 0;
	}
}

int maxAreaIndex(void* shapes[], Type* types, int n) {
	float maxArea = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		float area = returnArea(shapes[i], types[i]);
		if (area > maxArea) {
			maxArea = area;
			maxIndex = i;
		}
	}
	return maxIndex;
} 

int minAreaIndex(void* shapes[], Type* types, int n) {
	float minArea = 1e9;
	int minIndex = 0;
	for (int i = 0; i < n; i++) {
		float area = returnArea(shapes[i], types[i]);
		if (area < minArea) {
			minArea = area;
			minIndex = i;
		}
	}
	return minIndex;
} 

float returnPerimeter(void* value, Type type) { //Ham tra ve gia tri chu vi de so sanh
    switch (type) {
        case Type::SQUARE:
            return static_cast<const Square*>(value)->perimeter;
        case Type::RECTANGLE:
            return static_cast<const Rectangle*>(value)->perimeter;
        case Type::CIRCLE:
            return static_cast<const Circle*>(value)->perimeter;
        default:
            return 0;
	}
}

int maxPerimeterIndex(void* shapes[], Type* types, int n) {
	float maxPerimeter = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		float perimeter = returnPerimeter(shapes[i], types[i]);
		if (perimeter > maxPerimeter) {
			maxPerimeter = perimeter;
			maxIndex = i;
		}
	}
	return maxIndex;
} 

int minPerimeterIndex(void* shapes[], Type* types, int n) {
	float minPerimeter = 1e9;
	int minIndex = 0;
	for (int i = 0; i < n; i++) {
		float perimeter = returnPerimeter(shapes[i], types[i]);
		if (perimeter < minPerimeter) {
			minPerimeter = perimeter;
			minIndex = i;
		}
	}
	return minIndex;
}

void printAreaOnly(void* value, Type type) { // Ham in cac hinh co dien tich nho nhat, lon nhat theo format cua de
    switch (type) {
        case Type::SQUARE:
            cout << "Square a=" << static_cast<const Square*>(value)->side << " => area=" << static_cast<const Square*>(value)->area << endl;
            break;
        case Type::RECTANGLE:
            cout << "Rectangle w=" << static_cast<const Rectangle*>(value)->width << ", h= " << static_cast<const Rectangle*>(value)->height << " => area=" <<  static_cast<const Rectangle*>(value)->area << endl;
            break;
        case Type::CIRCLE:
            cout << "Circle r=" << static_cast<const Square*>(value)->side << " => area=" << static_cast<const Square*>(value)->area << endl;
            break;
 
	}
}

void printPerimeterOnly(void* value, Type type) { // Ham in cac hinh co chu vi nho nhat, lon nhat theo format cua de
    switch (type) {
        case Type::SQUARE:
            cout << "Square a=" << static_cast<const Square*>(value)->side << " => area=" << static_cast<const Square*>(value)->perimeter << endl;
            break;
        case Type::RECTANGLE:
            cout << "Rectangle w=" << static_cast<const Rectangle*>(value)->width << ", h= " << static_cast<const Rectangle*>(value)->height << " => area=" <<  static_cast<const Rectangle*>(value)->perimeter << endl;
            break;
        case Type::CIRCLE:
            cout << "Circle r=" << static_cast<const Square*>(value)->side << " => area=" << static_cast<const Square*>(value)->perimeter << endl;
            break;
 
	}
}

/*Dem so luong cac hinh da doc duoc*/
void countShapes(int& countSquare, int& countRectangle, int& countCircle, Type* types, int n) {
	for (int i = 0; i < n; i++) {
		switch (types[i]) {
        case Type::SQUARE:
           	countSquare++;
           	break;
        case Type::RECTANGLE:
            countRectangle++;
            break;
        case Type::CIRCLE:
            countCircle++;
            break;
	}
	}
}
