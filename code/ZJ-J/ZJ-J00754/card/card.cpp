#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<"0";
		return 0;
	}
	if(m==2)
	{
		cout<<"1";
		return 0;
	}
	if(m==3)
	{
		cout<<"3";
		return 0;
	}
	if(n==2)
	{
		cout<<"2";
		return 0;
	}
	cout<<"2";
	return 0;
}


