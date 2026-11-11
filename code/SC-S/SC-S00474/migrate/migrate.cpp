#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define MUBIAO ios_base::sync_with_stdio(0);
#define CESUO cin.tie(0);
#define frein freopen("migrate.in","r",stdin);
#define freout freopen("migrate.out","w",stdout);
#define mod 998244353
#define inf 1e14
#define pii pair<int,int>
using namespace std;
const int maxn=1e3+10;

int c,t,x[maxn],n,d,ans=0,f[maxn][maxn];

bool check(int l,int r){
	for(int i=l;i<=r;i++)
		for(int k=0;k<=(r-l+1);k++)
			f[i][k]=0;
	f[l][0]=1;
	for(int i=l;i<r;i++)
		for(int j=i+1;x[j]-x[i]<=d&&j<=r;j++)
				for(int k=0;k<=(i-l);k++)f[j][k+1]+=f[i][k];
	for(int i=0;i<=n;i++)
		if(f[r][i])return (f[r][i]==2);
	return false;
}

void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=check(i,j);
	cout<<ans<<endl,ans=0;
}

signed main(){
	MUBIAO CESUO
	frein freout
	cin>>c>>t;
	while(t--)Solve();
	return 0;
}