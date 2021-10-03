#pragma once
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#define nullstr ""
#define nullchar '\0'

class str
{
private:
	std::vector<char> arr;

public:
	str();
	~str();

	size_t size() const noexcept;
	void reszie(size_t newsize) noexcept;

	friend std::istream& operator>>(std::istream& stream, str& obj);
	friend std::ostream& operator<<(std::ostream& stream, str obj);
	str operator=(const char* right); // noexcept? // wtf is wrong
	//str operator+(str &right);// noexcept?
	//str operator+(const char* right);// noexcept?
	//str operator+(std::string &right);// noexcept?
	template<typename T>
	str operator+(T& right);

	bool operator!=(str& right) const noexcept;
	bool operator==(str& right) const noexcept;

	char& operator[](size_t position) noexcept(false);
};


template <typename T>
str str::operator+(T& right)
{
	assert(typeid(T) != typeid(int));
	assert(typeid(T) != typeid(float));
	assert(typeid(T) != typeid(double));
	assert(typeid(T) != typeid(bool));
	assert(typeid(T) != typeid(void));
	assert(typeid(T) != typeid(double));
	assert(typeid(T) != typeid(unsigned int));
	//todo: maybe replace assert with try{} catch{}
	
	const size_t i = arr.size();
	size_t k = 0;
	while (true)
	{
		if (right[k] == nullchar)
			break;
		else k++;
	}
	this->arr.resize(i + k);
	for (size_t j = 0; j < k; j++)
		arr[j + i] = right[j];
	return *this;
}