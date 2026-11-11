#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll xx[N];
int r[N],l[N];
void solve(){
	int n;ll d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>xx[i];
	for(int i=1;i<=n;i++){
		r[i]=r[i-1];
		while(r[i]<n&&xx[r[i]+1]-xx[i]<=d) r[i]++;
	}
	for(int i=n;i;i--){
		l[i]=(i<n?l[i+1]:n);
		while(l[i]>1&&xx[i]-xx[l[i]-1]<=d) l[i]--;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(xx[j]-xx[j-1]>d) break;
			vector<int>pl,pr;int p=i;
			while(1){
				pl.push_back(p);
				if(r[p]>=j){pl.push_back(j);break;}
				p=r[p];
			}
			p=j;
			while(1){
				pr.push_back(p);
				if(l[p]<=i){pr.push_back(i);break;}
				p=l[p];
			}
			reverse(pr.begin(),pr.end());
			int dif=0;
			for(int k=0;k<(int)pl.size();k++) dif+=pl[k]-pr[k];
			if(dif==1) ans++;
		}
	}
	cerr<<ans<<"\n";
}
signed main(){
	freopen("test.txt","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--) solve();
	return 0;
}