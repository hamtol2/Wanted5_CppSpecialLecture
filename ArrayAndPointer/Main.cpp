#include <iostream>

int main()
{
	// 배열.
	const int length = 5;
	int array[length] = { 1, 2, 3, 4, 5 };

	// 포인터.
	// 배열의 이름은 배열의 첫 원소의 주소를 반환.
	int* pointer = array;

	// 포인터에 덧셈 -> 메모리 점프.
	// 점프의 간격은 포인터 타입 크기만큼(예: int-4바이트).
	//for (int ix = 0; ix < length; ++ix)
	//{
	//	std::cout << &array[ix] << "\n";
	//	std::cout << (pointer + ix) << "\n\n";
	//}

	// 배열 요소에 10 곱하기.
	for (int ix = 0; ix < length; ++ix)
	{
		//array[ix] = array[ix] * 10;
		//array[ix] *= 10;

		// 포인터를 활용해 배열 편집.
		//*(pointer + ix) = *(pointer + ix) * 10;
		*(pointer + ix) *= 10;
	}

	//int* pointer2 = &array[0];
	//
	//// 하지만, 배열의 이름은 포인터는 아님(명확하게는).
	//auto arraySize = sizeof(array);
	//auto pointerSize = sizeof(pointer);
	//
	//if (arraySize != pointerSize)
	//{
	//	std::cout << "둘은 다름\n";
	//}
	//
	//std::cout << pointer << "\n";
	//std::cout << array << "\n";
	//std::cout << pointer2 << "\n";
	//std::cout << &array[0] << "\n";

	std::cin.get();
}