#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
int main()
{
	std::freopen("and.in","r",stdin);
	std::freopen("and.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	std::vector<int> list;
	int a = 0;
	list.reserve(n);
	for(int i = 0; i < n ;i++)
	{
		std::cin>>a;
		list.push_back(a);
	}
	
	
	int ans;
	for(int i = 0 ;i < n; i++)
	{
		for (int j = 0;j<n;j++){
			int temp = list.at(i) & list.at(j);
			if(temp> ans)
				ans= temp;
		}
	}

	std::cout<<ans;
}
