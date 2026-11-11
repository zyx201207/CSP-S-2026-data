#include<bits/stdc++.h>

std::vector<int> a;
int n;
int m;
int tmp;
int maxx;
int main()
{
	std::freopen("and.in", "r", stdin);
	std::freopen("and.out", "w", stdout);
	
	std::cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
	{
		long long tmp; 
		std::cin>>tmp;
		a.insert(a.end(), tmp);
	}
	//std::cout<<"======";
	for(int i = 0 ; i < n - 1 ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			
			//sstd::cout<<a[i]<<' '<<a[j]<<' '<<(a[i] and a[j])<<"    \n";
			if((a[i] and a[j]) > maxx)
			{
				maxx = a[i] and a[j];
			}
		}
	}
	//std::cout<<"======";
	std::cout<<maxx;
}
