#include "Car.h" // 자동차 클래스 헤더파일 포함
// 스포츠카 클래스 (자식 클래스) : 자동차 클래스에 터보 기능 추가

class SportsCar : public Car
{
public:
	bool bTurbo;
	// 터보 장치 ON?
	void setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() {   // 터보가 ON이 되어 있으면 가속이 빨리됨
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};

int main() {
    // 일반 자동차 객체 생성
    Car car1(50, (char*)"Carnival", 3);
    car1.display();

    car1.speedUp();
    car1.changeGear(4);
    car1.display();

    cout << "------------------" << endl;

    // 스포츠카 객체 생성
    SportsCar sp1;
    sp1 = SportsCar();

    // 부모 클래스 멤버 초기화 (생성자 없으니까 직접 설정은 불가 → 기본값 상태)
    sp1.changeGear(2);
    sp1.setTurbo(false);

    sp1.speedUp();
    sp1.display();

    cout << "---- Turbo ON ----" << endl;

    sp1.setTurbo(true);
    sp1.speedUp();
    sp1.display();

    return 0;
}