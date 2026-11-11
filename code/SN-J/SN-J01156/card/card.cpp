#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[100005];
int sum;
long long aand(auto ans, int num)
{
	if(num > m)
	{
		return sum = max(ans, sum);
	}
	
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i ++)
	{
		cin>>a[i];
	} 
	return 0;
}
