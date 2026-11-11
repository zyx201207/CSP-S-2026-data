#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=0x3f3f3f3f;
int c,T;
ll n,d;
ll x[2000005];
int nxt[2000005];
ll ans=0;
int cnt[2000005],dis[2000005];
void work(int s){
	for(int i=s;i<=n;i++){
		cnt[i]=0;
		dis[i]=inf;
	}
	cnt[s]=1;
	dis[s]=0;
	for(int u=s;u<=n;u++){
		if(cnt[u]==0) break;
		if(cnt[u]==2) ans++;
		for(int v=nxt[u];v>u;v--){
			if(dis[v]<=dis[u]) break;
			dis[v]=dis[u]+1;
			cnt[v]+=cnt[u];
			if(cnt[v]>2) break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//don't forget to delete!!!!!
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int lst=n;
		for(int i=n;i>=1;i--){
			while(x[lst]-x[i]>d) lst--;
			nxt[i]=lst;
			//cout<<i<<' '<<nxt[i]<<'\n';
		}
		if(c==11||c==12){
			int f=2*nxt[1]-2;
			if(f<=3||f>n) cout<<"0\n";
			else cout<<n-f+1<<'\n';
			continue;
		}
		ans=0;
		if(c==13||c==14){
			int l=1,r=nxt[1];
			while(nxt[l]<n) l++;
			for(int i=1;i<=n;i++){
				if(l<=i||n<=r) break;
				r=nxt[i];
				if(r-l+1==2){
					ans+=n-r;
				}
				if(r-l+1>2) break;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			work(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}