#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll cid,T,n,m,a[N],l[N],r[N],p[N],f[N],cnt[11][11];
struct P{
	ll x,w;
};
vector<P>cur;
void dfs(ll x,ll d){
	cnt[x][d]++;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>m) break;
		dfs(i,d+1);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cid>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(cid<=2){
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=0;k<n;k++){
						cnt[j][k]=0;
					}
				}
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					for(int k=0;k<n;k++){
						if(cnt[j][k]){
							if(cnt[j][k]==2) ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(13<=cid&&cid<=14||n==1){
			cout<<"0\n";
			continue;
		}
		if(11<=cid&&cid<=12){
			ll d=upper_bound(a+1,a+n+1,a[1]+m)-a-1-1;
			if(d==2) cout<<max(0ll,n-3)<<"\n";
			else cout<<"0\n";
			continue;
		}
		if(cid<=10){
			for(int i=1;i<=n;i++){
				l[i]=lower_bound(a+1,a+n+1,a[i]-m)-a;
				r[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
			}
			ll ans=0;
			for(int i=1;i<=n;i++){
				cur.clear();
				cur.push_back({i,1});
				ll ls=0;
				for(int j=i+1;j<=n;j++) f[j]=0;
				for(int j=i+1;j<=n;j++){
					ll mi=1e18,mx=0,fr=0;
					for(auto k:cur){
						p[k.x+1]+=k.w;
						p[r[k.x]+1]-=k.w;
						mi=min(mi,k.x+1);
						mx=max(mx,r[k.x]+1);
						fr=max(fr,r[k.x]);
					}
					if(mi==1e18) break;
					if(fr==ls) break;
					ls=fr;
					for(int k=mi;k<=mx;k++){
						p[k]+=p[k-1];
						p[k-1]=0;
						if(!f[k]&&p[k]==2) ans++,f[k]=1;
						if(0<p[k]&&p[k]<3) cur.push_back({k,p[k]});
					}
					p[mx]=0;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<"0\n";
	}
	return 0;
}
//2h 16pts
//ÏÊÑª°¡ Ã»ÓÐÉø³ö³á°ò
//ÎÒµÄÑÛÀá£¬Òç³öÁËÑÛ¿ô
//~~~ ~~~~~ ~   ~~~ ~~~~~ !
//~~~ ~~~~~ ~   ~~~ ~~~~~ !
