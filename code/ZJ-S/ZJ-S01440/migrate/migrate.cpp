#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,pre[N],nxt[N],cntl[N],l[N],r[N],cntr[N],x[N],ans;
vector<int> g[N];
void solve(){
	//int maxn=0;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		pre[i]=nxt[i]=cntl[i]=cntr[i]=l[i]=r[i]=0;
	}
	for(int i=1,j=1;i<=n;i++){
		while(j+1<=n&&x[j+1]-x[i]<=d)j++;
		nxt[i]=j;
		if(j!=i){
			cntl[j]++;
			g[j].push_back(i);
		}
		//cout<<cntl[i]<<" ";
	}
	for(int i=n,j=n;i>=1;i--){
		while(j-1>=1&&x[i]-x[j-1]<=d)j--;
		pre[i]=j;
		if(j!=i){
			cntr[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(cntl[i]>0)l[i]=l[pre[i]]+cntl[i];
	}
	for(int i=n;i>=1;i--){
		if(cntr[i]>0)r[i]=r[nxt[i]]+cntr[i];
	}
	for(int i=4;i<=n;i++){
		//if(cntl[i]<2)continue;
		int cl=0,cr=1,t=pre[i]+1;
		if(t>=i)continue;
//		while(cntl[t]>0){
//			cl+=cntl[t];
//			t=pre[t];
//		}
		cl=l[t];
		t=i;
//		if(nxt[pre[i]]==i){
//			while(cntr[t]>0){
//				cr+=cntr[t];
//				t=nxt[t];
//			}
//		}
		if(nxt[pre[t]]==t&&nxt[pre[i]+1]==i)cr+=r[t];
		ans+=cl*cr;
		//maxn=max(maxn,cl*cr);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		solve();
	}
	return 0;
}
