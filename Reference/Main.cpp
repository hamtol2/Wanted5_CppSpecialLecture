#include <iostream>
#include <string>

// 의도 -> const &가 아니라 &가 파라미터인 경우,
// 출력용인 경우가 많음.
void Test(const std::string& name)
{

}

// const &는 읽기 전용이라는 의도.
// 누군가의 코드에서 const &를 보면 읽기 전용이구나라고 이해.
void Test(const int& ref)
{
	//ref *= 10;
}

void ChangeNumber(int* const pointer)
{
	//*number *= 100;
	*pointer = *pointer * 100;
	//pointer = nullptr;
}

int main()
{
	// 컴파일러(Compiler)?
	// 기계어(HW 종속적)로 코딩 
	// -> 어셈블러(Asembly) - HW 종속적.
	// -> 컴파일러(C 언어/Unix).

	int number = 10;

	ChangeNumber(&number);

	// 포인터.
	int* pointer = &number;

	// 역참조를 활용해서 값 설정.
	*pointer = 20;

	// 포인터는 나중에 다른 주소를 저장할 수 있음.
	pointer = nullptr;

	// 참조(LValue Reference) 변수.
	int& /*const*/ reference = number;

	// 값 설정.
	reference = 30;

	// 참조 변수는 중간데 다른 변수를 참조할 수 없음.
	int number2 = 50;
	reference = number2;

	// number -> [10] <- reference.
	std::cout << &number << "\n";
	std::cout << &pointer << "\n";
	std::cout << &reference << "\n";
}