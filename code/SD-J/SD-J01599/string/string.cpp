#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=2e5+10;
/*====================*/
int n;
int a[N],c[N];
/*====================*/
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char s;
		cin>>s;
		c[i]=s-'a';
//		p(c[i]);
	}
	
	int ans=0;
	int lx=1,rx=n;
	int lsh=a[1],rsh=a[n];
	while(lx<rx)
	{
//		p(lsh);
//		p(rsh);
//		p(lx);
//		p(rx);
		if(lsh<rsh)
		{
			rsh-=lsh;
			if(c[lx]!=c[rx])ans+=lsh;
			lsh=a[++lx];
		}
		else if(lsh==rsh)
		{
			if(c[lx]!=c[rx])ans+=lsh;
			lsh=a[++lx],rsh=a[--rx];
		}
		else if(lsh>rsh)
		{
			lsh-=rsh;
			if(c[lx]!=c[rx])ans+=rsh;
			rsh=a[--rx]; 
		}
//		else cout<<"error";
	}
	cout<<ans<<endl;
	return 0;
}

