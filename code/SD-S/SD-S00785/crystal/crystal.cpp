#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int a[1000005];
int main()
{
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int one=a[1]+=m;
		if(one==a[i])
		{
			cout<<"2";
			break;
		}
		int buzhidao=a[1]+=3;
		int miku=a[2]+=(m-3);
		if(buzhidao&&miku==a[i])
		{
			cout<<"3";
			break;
		}
	    int teto=a[1]+=5;
		int gumi=a[2]+=(m-5);
		if(teto&&gumi==a[i])
		{
			cout<<"4";
			break;
		}
	}        
    return 0;
}
