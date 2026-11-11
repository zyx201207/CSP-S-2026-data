#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
char c[]="0123456789ABCDEF";
int n,m,a[100005],e[105]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxx==a[i]&&m==2)
		{
			cout<<maxx;
			return 0;
		}
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	
	return 0;
}
