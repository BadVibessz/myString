#pragma once
#include <iostream>
#include <vector>
#include <string>

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
	str operator=(const char* right) noexcept;
	str operator+(str& right) noexcept;
	str operator+(const char* right) noexcept;
	str operator+(std::string& right) noexcept;

	bool operator!=(str& right) noexcept;
	bool operator==(str& right) noexcept;
	
	char& operator[](size_t position);
};


str::str()
{
	arr = std::vector<char>(NULL);
}

str::~str() { arr.clear(); }

size_t str::size() const noexcept { return this->arr.size(); }

void str::reszie(size_t newsize) noexcept { this->arr.resize(newsize); }

str str::operator=(const char* right) noexcept
{
	size_t i = 0;
	while (right[i]) { i++; }
	arr.resize(i);

	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = right[i];

	return *this;
}

str str::operator+(str& right) noexcept
{
	size_t i = arr.size();
	this->arr.resize(i + right.size());
	for (size_t j = 0; j < right.arr.size(); j++)
		arr[j + i] = right.arr[j];
	right.arr.clear();
	return *this;
}

str str::operator+(const char* right) noexcept
{
	size_t i = arr.size();
	size_t k = 0;
	while (right[k]) { k++; }
	this->arr.resize(i + k);
	for (size_t j = 0; j < k; j++)
		arr[j + i] = right[j];
	return *this;
}

str str::operator+(std::string& right) noexcept
{
	return *this;
}

bool str::operator!=(str& right) noexcept
{
	if (this->arr != right.arr) return true; return false;
}

bool str::operator==(str& right) noexcept
{
	if (this->arr == right.arr) return true; return false;
}

char& str::operator[](size_t position)
{
	return this->arr[position];
}


std::istream& operator>>(std::istream& stream, str& obj)
{
	std::istream::sentry sentry(stream);
	if (!sentry)
		return stream;

	std::vector<char> temp;
	int next;

	while ((next = stream.get()) != stream.eof() && !std::isspace(next))
		temp.push_back(next);
	temp.push_back('\0');
	obj = &temp[0];

	return stream;
}

std::ostream& operator<<(std::ostream& stream, str obj)
{
	for (size_t i = 0; i < obj.arr.size(); i++)
		stream << obj.arr[i]; // std::char
	return stream;
}


