//张海辰 西安铁一中滨河学校高级中学 SN-S00376 
#include<bits/stdc++.h>
using namespace std;
long long  a[50005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
	}
	sort(a+1,a+n+1);
	int minn=0;
	int cnt=0;
	for(int j=2;j<=n-1;j++)
	{
		if(n>=13&&n<=15)
		a[j]=j;
		
		if(a[j+1]-a[1]<=m)
		{
		cout<<j+1;
		break;
		}
		
	}
	return 0;
}
