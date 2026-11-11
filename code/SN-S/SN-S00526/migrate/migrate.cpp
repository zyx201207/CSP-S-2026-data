#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

template<typename T1,typename T2>
inline void MIN(T1 &a,T2 b) {a=a<b?a:b;}
template<typename T1,typename T2>
inline void MAX(T1 &a,T2 b) {a=a<b?b:a;}

const int N=2e6+10;

int n; ll d,x[N];
int f[N],f2[N],g[N]; ll ans,s[N];

void work()
{
	cin>>n>>d; ans=0;
	for (int i=1;i<=n;i++) cin>>x[i];
	
	x[n+1]=4e18; x[n+2]=7e18;
	for (int i=1;i<=n;i++)
	{
		f[i]=g[i]=s[i]=f2[i]=0;
		int l=lower_bound(x+1,x+n+1,x[i]-d)-x;
		int r=lower_bound(x+1,x+n+1,x[i+1]-d)-x-1;
		int r2=lower_bound(x+1,x+n+1,x[i+2]-d)-x-1;
		
		MIN(r,i-1); MIN(r2,i-1);
		if (l<=r) f[i]=r-l+1+f[l],g[i]+=g[l];
		if (l<=r2) f2[i]=r2-l+1+f[l];
		
		if (l+1<=r) g[i]+=f2[l]-f[l];
	}
	
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(x+1,x+n+1,x[i]-d)-x;
		int r=i-1,v=0;
		
		if (l<=r) v+=g[l];
		if (l+1<=r) v+=f2[l]-f[l];
		ans+=v;// cout<<i<<" "<<v<<" "<<f[i]<<" "<<f2[i]<<" "<<g[i]<<"!\n";
	}
	
	cout<<ans<<"\n";
	
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t; cin>>t>>t;
	while (t--) work();

	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 1
//10 21
//0 7 14 21 28 35 42 49 56 63

//0 1
//6 3
//0 1 2 3 4 7


