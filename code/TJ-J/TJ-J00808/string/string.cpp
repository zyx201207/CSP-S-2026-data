#include<iostream>
#include<cstdio>
#include<string>
bool is_cycle(const std::string& str)
{

	const char* front = &str.at(0);
	const char* end =  &str.at(str.length() - 1);
	for(int i ; i < str.length() / 2 ; i++)
	{
		if(*front != *end)
			return false;
		front++;
		end--;
	}
	return true;
}

unsigned int count_differ(const std::string& str)
{
	unsigned int count = 0 ;
	const char* front = &str[0];
	const char* end =  &str[str.length() - 1];
	for(unsigned int i = 0; i < str.length() / 2 ; i++)
	{
		if(*front != *end)
			count++;
		front++;
		end--;
	}
	return count;
}
int main()
{
	std::freopen("string.in","r",stdin);
	std::freopen("string.out","w",stdout);
	std::string s;
	int total;
	std::cin>>total;
	int count;
	char character;
	for(int i = 0 ; i < total ;i++)
	{
		std::cin>>count>>character;
		for(int i = count ; i > 0 ;i--)
			s += character;				
	}
	std::cout<<count_differ(s)<<std::endl;
	return 0;
} 
