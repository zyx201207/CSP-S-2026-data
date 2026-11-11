#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
struct a
{
	int count;
	int value;
};

int main()
{
	std::freopen("card.in","r",stdin);
	std::freopen("card.out","w",stdout);
	long long n,m;
	std::cin>>n,m;
	std::vector<a> list;
	list.reserve(n);
	a item;
	for(int i = 0; i < n ;i++)
	{
		std::cin>>item.value;
		list.push_back(item);
	}
	for(int i = 1;i<=n;i++)
		std::cout<<i<<" ";
	return 0;
}
