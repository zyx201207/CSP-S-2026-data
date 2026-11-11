#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N=2e6+5;
int c,T,n,d,x[N];
struct BF{
	int f[5005][5005],g[5005][5005];
	void solve(){
		memset(f,-1,sizeof f),memset(g,0,sizeof g);
		for(int l=1;l<=n;l++){
			f[l][l]=0,g[l][l]=1;
			for(int r=l,L=l,s=1,R=l;r<=n;r++){
				while(x[r]-x[L]>d){
					if(L<=R)s-=g[l][L];
					L++;
				}
				if(l==r)continue;
				if(L==r)break;
				if(L>R){
					R=L,s=g[l][L];
					while(R+1<r&&f[l][R+1]==f[l][L])s+=g[l][++R];
				}
				f[l][r]=f[l][L]+1,g[l][r]=s;
				if(R==r-1&&f[l][r]==f[l][L])s+=g[l][++R];
			}
		}
		int ans=0;
		for(int l=1;l<=n;l++)for(int r=l+3;r<=n;r++)
			if(f[l][r]!=-1&&g[l][r]==2)ans++;
		cout<<ans<<'\n';return;
	}
}_;
struct BB{
	void solve(){
		int mid=(n+1)/2,ans=0;
		for(int l=1;l<mid;l++){
			if(x[mid+1]-x[l]<=d){
				int ps=upper_bound(x+1,x+n+1,x[mid-1]+d)-x-1;
				if(ps<=n)ans+=n-ps+1;
			}
			else{
				int ps=upper_bound(x+1,x+n+1,x[mid-1]+d)-x-1;
				if(ps>mid)ans+=ps-1-mid;
			}
		}
	}
}B;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c<=10||n<=5000)_.solve();
		else if(c==13||c==14)B.solve();
	}
	return 0;
}

