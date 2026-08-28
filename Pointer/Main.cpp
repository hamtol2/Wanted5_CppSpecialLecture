#include <iostream>

// 함수를 통한 값 변경.
void ChangeValue(int* data)
{
	*data = 20;
}

int main()
{
	// 변수 선언.
	int number = 10;

	// 함수 호출.
	ChangeValue(&number);

	// 포인터(주소를 저장하는 변수).
	int* pointer = &number;

	// 다른 포인터.
	int* pointerB = nullptr;

	// 주소 비교.
	// 아래 비교는 어떤 값을 비교하는가?
	// 주소 값이 같은지 비교 -> 같은 위치.
	if (pointer == pointerB)
	{
		std::cout << "주소가 일치함.\n";
	}

	// 더블 포인터
	// - 주소를 저장
	// - 포인터의 주소를 저장.
	//int** doublePointer = &pointer;

	// 삼차 포인터.
	// - 주소를 저장.
	// - 포인터를 저장하는 포인터의 주소 저장.
	//int*** tripplePointer = &doublePointer;

	// 참조: 주소를 저장하는 것.
	// 역참조 -> 저장한 주소를 통해 접근하는 방법.
	//int value = *pointer;
	//value = **doublePointer;
	//value = ***tripplePointer;

	std::cin.get();
}