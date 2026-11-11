#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int Read(){int x=0,f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(48<=ch&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();return x*f;}
const int kN=5e5+10,kM=1e5+10,kMod=1e9+7,kInf=1e9;

void Work();

int a[kN];

signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;while(T--)Work();
}

void Work()
{
	int n=Read(),m=Read();
	for(int i=1;i<=n;i++)a[i]=Read();
	sort(a+1,a+n+1);
	int cost=0,r=1,ans=0;
	for(int l=1;l<=n;l++)
	{
		while(r+1<=n&&cost+abs(a[r+1]-a[r])*(r-l+1)<=m)
			cost+=abs(a[r+1]-a[r])*(r-l+1),r++;
		ans=max(ans,r-l+1),cost-=abs(a[r]-a[l]);
	}
	cout<<ans<<endl;
}
/*
	
*/