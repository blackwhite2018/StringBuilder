#include <iostream>
#include <stdio.h>

int ft_strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;
	return count;
}

class StringBuilder
{
private:
	char *str_;

public:
	StringBuilder()
	{
		str_ = new char[1];
		if (str_)
			str_[0] = '\0';
	}

	StringBuilder(char *str)
	{
		int length = ft_strlen(str);

		str_ = new char[length];
		for (int i = 0; i < length; i++)
			str_[i] = str[i];
		str_[length] = '\0';
	}

	StringBuilder(StringBuilder &str)
	{
		char *ptr = (char *)str.get();
		int length = ft_strlen(ptr);

		str_ = new char[length];
		for (int i = 0; i < length; i++)
			str_[i] = ptr[i];
		str_[length] = '\0';
	}

	char *get()
	{
		return str_;
	}

	void padEnd(char symbol)
	{
		int length = ft_strlen(str_) + 2;
		char *newStr = new char[length];
		int index = 0;

		while (index < length - 2)
		{
			newStr[index] = str_[index];
			index++;
		}
		newStr[index++] = symbol;
		newStr[index] = '\0';
		delete[] str_;
		str_ = newStr;
	}

	void padEnd(StringBuilder str)
	{
		char *ptr = str.get();
		int length = ft_strlen(str_) + ft_strlen(ptr) + 1;
		char *newStr = new char[length];
		int index = 0;
		int posNewStr = 0;

		while (str_[index] != '\0')
			newStr[posNewStr++] = str_[index++];
		index = 0;
		while (ptr[index] != '\0')
			newStr[posNewStr++] = str_[index++];
		newStr[posNewStr] = '\0';
		delete[] str_;
		str_ = newStr;
	}

	void padStart(char symbol)
	{
		int length = ft_strlen(str_) + 2;
		char *newStr = new char[length];
		int index = 0;

		newStr[index++] = symbol;
		while (index < length - 1)
		{
			newStr[index] = str_[index];
			index++;
		}
		newStr[index] = '\0';
		delete[] str_;
		str_ = newStr;
	}

	void print()
	{
		int index = 0;

		while (str_[index] != '\0')
			std::cout << str_[index++];
		std::cout << '\n';
	}

	void read()
	{
		char *str = new char[256];
		std::cin.getline(str, 256);
		delete[] str_;
		str_ = str;
	}

	~StringBuilder()
	{
		delete[] str_;
	}
};

class Person
{
private:
	char *name_;

	Person() {}

	Person(Person &person) {}

public:
	Person(char *name)
	{
		name_ = new char[ft_strlen(name) + 1];
		int index = 0;

		while (name[index] != '\0')
		{
			name_[index] = name[index];
			index++;
		}
		name_[index] = '\0';
	}

	char *get()
	{
		return name_;
	}

	Person *prototype()
	{
		Person *person = new Person(name_);
		return person;
	}

	~Person()
	{
		delete[] name_;
	}
};

class Flat
{
private:
	Person **tenants_;
	int length_;

	Flat(Flat &flat) {}

public:
	Flat()
	{
		length_ = 0;
		tenants_ = new Person *[length_];
	}

	void add(Person *person)
	{
		Person **newTenants = new Person *[++length_];
		int index = 0;
		while (index < length_ - 1)
		{
			newTenants[index] = tenants_[index]->prototype();
			index++;
		}
		newTenants[index] = person;
		index = 0;
		while (index < length_ - 1)
			delete tenants_[index];
		tenants_ = newTenants;
	}

	void rm(int key)
	{
		Person **newTenants = new Person *[--length_];
		int index = 0;
		while (index < length_ + 1)
		{
			if (key != index)
				newTenants[index] = tenants_[index]->prototype();
			index++;
		}
		index = 0;
		while (index < length_ - 1)
			delete tenants_[index];
		tenants_ = newTenants;
	}

	Flat *prototype()
	{
		Flat *flat = new Flat();
		flat->length_ = length_;
		flat->tenants_ = tenants_;
		return flat;
	}

	~Flat()
	{
		int index = 0;
		while (index < length_)
			delete tenants_[index];
		delete[] tenants_;
	}
};

class House
{
private:
	House(House &house) {}

	Flat flats_[3];
	int length_;

public:
	House()
	{
		flats_[0] = Flat();
		flats_[1] = Flat();
		flats_[2] = Flat();
	}

	Flat *get(int nbr)
	{
		if (nbr < length_)
			return flats_[nbr].prototype();
	}
};

int main()
{
	StringBuilder sb1("test str\0");
	StringBuilder sb2(sb1);
	sb1.print();
	sb2.padEnd(sb1);
	sb2.padStart('W');
	sb2.print();
	sb2.read();
	sb2.print();
	return 0;
}
