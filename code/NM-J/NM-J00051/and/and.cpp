#include<bits/stdc++.h>
using namespace std;
long long w[100005];
long long n,m,k;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a>k)
		{
			k=a;
		}
		w[a]+=1;
	}
	for(int i=1;i<=k;i++)
	{
		if(w[i]==2)
		{
			cout<<w[i];
			return 0;
		}
	}
	return 0;
}
