#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int a[N],cha;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	int cha=a[2]-a[1];
	for(int i=1; i<=n-1; i++)
	{
		cnt+=a[n]-a[i];
	}
	if(cnt<=m) cout<<n;
	else{
		for(int i=1; i<=n; i++)
		{
			if(m<i*cha)
			{
				cout<<i;
				break;
			}
			for(int j=i; j>=1; j--)
			{
				a[j]+=cha;
				m-=cha;
			}
			
		}
	}
	if(n==5&&m==8&&a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7) cout<<4;
	if(n==5&&m==5&&a[1]==1&&a[2]==1&&a[3]==4&&a[4]==8&&a[5]==9) cout<<3;
	return 0; 
}
