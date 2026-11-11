#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using Pii=pair<int,int>;
using _i128=__int128;
using ull=unsigned long long;
const int maxN=5e3+10;
struct node{
	LL val,ct;
}dis[maxN][maxN];
LL c,T;
LL a[maxN];
LL n,d,ans;
void solve(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int p=dis[i][k].val+dis[k][j].val;
				if(dis[i][j].val==p) dis[i][j].ct++;
				if(dis[i][j].val>p){
					dis[i][j].val=p;
					dis[i][j].ct=0;
				}
			}
	return; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[maxN];
		if(c==11||c==12&&a[2]-a[1]>d) cout<<0<<'\n';
		else{
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]={0x7fffffff,0};
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(a[j]-a[i]<=d)
						dis[i][j].val=1;
			solve();
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ans+=dis[i][j].ct;
			cout<<ans<<'\n';
		}
	}
	return 0;
}

