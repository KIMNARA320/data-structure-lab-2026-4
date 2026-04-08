#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"
using namespace std;
int main() {
	//Rectangle 1 객체 생성
	Rectangle rect1(3.4, 2.5);
	cout << "Rectangle 1:" << endl;
	//printf("Rectangle 1:\n")
	cout << "Area: " << rect1.getArea() << endl;
	//printf("Area: %If", rect1.getArea());
	cout << "Perimeter: " << rect1.getPerimeter() << endl;
	cout << "Is Square ? " << boolalpha << rect1.isSquare() << endl;
	printf("=============================================\n");

	//Pet 클래스 테스트
	Pet myPet("Kong", 5, "Cat");
	cout << "My pet's name is " << myPet.getName() << endl;
	//Puppy 클래스 테스트
	Puppy myPuppy("Lucky", 10, "Dog", "Munchicken");
	cout << "My puppy's breed is " << myPuppy.getBreed() << endl;
	printf("=============================================\n");

	//StreamingService 테스트
	MusicStreamingService myService("Spotify");
	//음악 Service에 추가하기;
	myService.addMusic("SWIM", "BTS", "ARIRANG", 2026);
	myService.addMusic("RUDE", "Hearts2Hearts", "RUDE", 2026);
	myService.addMusic("BANGBANG", "IVE", "REVIVE", 2026);
	myService.addMusic("JUMP", "BlackPink", "Jump", 2025);
	myService.addMusic("ShutDown", "BlackPink", "BornPink", 2022);
	//title로 search
	string music_title;
	cout << "Enter the Music title: ";
	cin >> music_title;
	//scanf_sf("%s", &music_title);
	Music* result = myService.searchBytitle(music_title);
	if (result != NULL) {
		cout << "Found" << result->getTitle() << "by" << result->getArtist() << endl;
	}
	else {
		cout << "Not Found" << endl;
	}

	string artist_name;
	cout << "Enter the Artist Name : ";
	cin >> artist_name;

	vector<Music*>artistResult = myService.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << "Found" << artistResult.size() << "songs by" << artist_name << " : " << endl;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not Found" << endl;
	}
	return 0;
}