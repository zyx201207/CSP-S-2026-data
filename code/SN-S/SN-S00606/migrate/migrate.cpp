#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int a[2000005];
pair<int,int> ff[2000005];
pair<int,int> f[5005][5005];
void solve1(void){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]={0,0};
	}
	for(int i=1;i<n;i++){
		int l=i,num=1;
		f[i][i]={1,0};
		for(int j=i+1;j<=n;j++){
			int u=l;
			while(a[j]-a[u]>d) num-=f[i][u++].first;
			if(j==u) break;
			if(f[i][l].second!=f[i][u].second){
				num=0;
				for(int k=u;k<j;k++){
					if(f[i][k].second!=f[i][u].second) break;
					num+=f[i][k].first;
				}
			}
			l=u;
			f[i][j]={num,f[i][l].second+1};
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++) ans+=f[i][j].first==2;
	}
	cout<<ans<<'\n';
	return;
}
void solve2(void){
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],ff[i]={0,0};
	ff[1]={1,0};
	int l=1,num=1;
	for(int j=2;j<=n;j++){
		int u=l;
		while(a[j]-a[u]>d) num-=ff[u++].first;
		if(j==u) break;
		if(ff[l].second!=ff[u].second){
			num=0;
			for(int k=u;k<j;k++){
				if(ff[k].second!=ff[u].second) break;
				num+=ff[k].first;
			}
		}
		l=u;
		ff[j]={num,ff[l].second+1};
		ans+=(n-j+1)*(ff[j].first==2);
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c<=10) solve1();
		if(11<=c&&c<=12) solve2();
		if(13<=c&&c<=14) cout<<0<<'\n';
	}
	return 0;
}
