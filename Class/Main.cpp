#include <iostream>

// 클래스.
class Character
{
public:
	float attack = 10.0f;

	// 하위 계층에서 확장이 가능하도록 가상 함수로 선언.
	// virtual 가상 -> 뭐가 진짜일지 모름(실행할 때 실제 어떤 함수일지 몰라서).
	virtual void Attack()
	{
		std::cout << "캐릭터 공격. 공격력: " << attack << "\n";
	}
};

class Warrior : public Character
{
public:
	float armor = 50.0f;
	
	virtual void Attack() override
	{
		std::cout << "워리어 공격. 공격력: " << attack << "\n";
	}
};

class Mage : public Character
{
public:
	float mana = 100.0f;

	virtual void Attack() override
	{
		std::cout << "Mage 공격. 공격력: " << attack << "\n";
	}
};

//              Character
//                ^   ^
//               /     \
//           Warrior   Mage
//


int main()
{
	// 클래스를 사용해서 객체 생성.
	Character character;
	//character.attack = 20.0f;
	//character.Attack();

	// 포인터로 객체 사용.
	//Character* pointer = &character;
	////(*pointer).Attack();
	////(*pointer).attack = 30.0f;
	//pointer->attack = 30.0f;
	//pointer->Attack();

	// 캐릭터를 상속한 워리어 객체 생성. (Is-A).
	// Warrior는 Character다 => Warrior is a Character.
	// Is-A의 성립 방향은 한 방향. != Character is a Warrior.
	Warrior warrior;
	warrior.attack = 50.0f;
	warrior.armor = 5.0f;
	//warrior.Attack();

	// 법사.
	// Mage는 Character다 => Mage is a Character.
	Mage mage;
	mage.mana = 50.0f;
	mage.attack = 30.0f;
	//mage.Attack();

	// 캐릭터 포인터.
	// 업 캐스팅 (상위 계층으로 형변환).
	// 항상 안전하기 때문에 형변환 연산을 생략해도 됨.
	//Character* mainCharacter = &warrior;
	//mainCharacter->Attack();

	// 모든 캐릭터 타입을 배열로 관리하고 싶음.
	Character* level[3] = {};
	level[0] = &character;
	level[1] = &warrior;
	level[2] = &mage;

	level[1]->armor = 

	// 모든 캐릭터에 대해 공격 실행.
	for (Character* const character : level)
	{
		character->Attack();
	}
}