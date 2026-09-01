#include <iostream>
#include <vector>

class Character
{
public:
	virtual ~Character()
	{
	}

	virtual void Attack()
	{
	}
};

class Warrior : public Character
{
public:
	void UseShield()
	{
		std::cout << "Use Shield\n";
	}

private:
	virtual void Attack() override
	{
		std::cout << "Warrior Attacks.\n";
	}
};

class Mage : public Character
{
private:
	virtual void Attack() override
	{
		std::cout << "Mage Attacks.\n";
	}
};

std::vector<Character*> characters;

template<typename T, typename = std::enable_if<std::is_base_of<Character, T>::value>>
T* SpawnActor()
{
	T* newActor = new T();
	characters.emplace_back(newActor);
	return newActor;
}

int main()
{
	const int count = 10;
	characters.reserve(count);
	for (int ix = 0; ix < count; ++ix)
	{
		if (ix % 2 == 0)
		{
			SpawnActor<Warrior>();
		}
		else
		{
			SpawnActor<Mage>();
		}
	}

	for (Character* const character : characters)
	{
		character->Attack();
		
		Warrior* warrior = dynamic_cast<Warrior*>(character);
		if (warrior)
		{
			warrior->UseShield();
		}
	}

	std::cin.get();
}