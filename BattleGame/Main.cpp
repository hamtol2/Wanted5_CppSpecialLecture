#include <iostream>
#include <string>
#include <vector>

/*
* 데이터 -> 변수 | 동작 -> 함수.
* 이름/체력/공격력
* 모든 캐릭터가 공격해야함.
*/

class Character
{
public:
	Character(
		const std::string& name,
		float hp = 100.0f,
		float attack = 10.0f)
		: name(name), hp(hp), attack(attack)
	{
	}

	// 공격.
	// 값 전달/포인터 전달/참조 전달.
	virtual void Attack(Character* other)
	{
		if (!other)
		{
			return;
		}

		other->Damage(attack);
	}

	virtual void Damage(float damage)
	{
		hp -= damage;
	}

protected:
	std::string name;
	float hp = 100.0f;
	float attack = 10.0f;
};

class Warrior : public Character
{
public:
	Warrior()
		: Character("Warrior", 200.0f)
	{
	}

	virtual void Attack(Character* other) override
	{
		Character::Attack(other);
		std::cout << "Sword Attack.\n";
	}
};

class Mage : public Character
{
public:
	Mage()
		: Character("Mage ", 50.0f, 50.0f)
	{}

	virtual void Attack(Character* other) override
	{
		Character::Attack(other);
		std::cout << "Magic Attack.\n";
	}
};

class Monster : public Character
{
public:
	Monster()
		: Character("Monster", 20.0f, 20.0f)
	{}

	virtual void Attack(Character* other) override
	{
		Character::Attack(other);
		std::cout << "Claw Attack.\n";
	}
};

std::vector<Character*> level;

template<typename T,
	typename = std::enable_if<std::is_base_of<Character, T>::value>>
T* SpawnActor()
{
	T* newActor = new T();
	level.emplace_back(newActor);
	return newActor;
}

void Release()
{
	for (auto*& actor : level)
	{
		delete actor;
		actor = nullptr;
	}

	level.clear();
}

int main()
{
	Warrior* warrior = SpawnActor<Warrior>();
	SpawnActor<Mage>();
	Monster* monster = SpawnActor<Monster>();

	warrior->Attack(monster);

	Release();
}