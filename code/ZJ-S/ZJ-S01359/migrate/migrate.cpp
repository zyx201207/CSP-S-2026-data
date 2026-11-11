#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int n,d;
const int nn=2e6+5;
int x[nn],nxt[nn];
#define pb push_back
vector<int> e[nn];
int fl1[nn],fl2[nn];
inline bool chk(int a,int b){
	if(a<=0) return 0;
	return (x[b]-x[a]<=d);
}
int s0[nn],s1[nn];
inline int getsum(int l,int r){
	l=max(l,1ll),r=min(r,n);
	if(l>r) return 0;
	return r-l+1;
}
int ans;
void dfs(int x){
	fl1[x]=0,fl2[x]=0;
	if(nxt[nxt[x]]){
		if(chk(nxt[x]-1,nxt[nxt[x]])&&nxt[x]-1>x){
			fl1[x]++;
		}
		if(chk(nxt[x]-2,nxt[nxt[x]])&&nxt[x]-2>x){
			fl1[x]++;
		}
		if(fl1[x]==1){
			fl2[x]=0;
			if(chk(x-1,nxt[x]-1)) fl2[x]=1;
		}
	}
	for(int v:e[x]){
		dfs(v);
	}
	s0[x]=0;s1[x]=0;
	if(fl1[x]<=1){
		if(fl2[x]){
			s1[x]=1;
		}
		else if(fl1[x]==0){
			s0[x]=1;
			for(int v:e[x]){
				s0[x]+=s0[v];
				s1[x]+=s1[v];
			}
		}
		else{
			s1[x]=1;
			for(int v:e[x]){
				s1[x]+=s0[v];
			}
		}
	}
	for(int v:e[x]){
		int now0=0,now1=0;
		for(int w:e[v]){
			now0+=s0[w];
			now1+=s1[w];
		}
		int pr2;
		if(x-2>=0) pr2=nxt[x-2];
		else pr2=0;
		int add0=getsum(max(x+1,nxt[x-1]+1),nxt[x]);
		int add1=getsum(max(pr2+1,x+1),min(nxt[x],nxt[x-1]));
		ans+=add0*now1;
		// cout<<x<<" "<<v<<" "<<now0<<" "<<now1<<" "<<add0<<" "<<add1<<" "<<nxt[x]<<" "<<max(x+1,nxt[x-1]+1)<<endl;
		if(!chk(v-1,x-1)) ans+=add1*now0;
		ans+=add1;
		// cout<<x<<" "<<v<<" "<<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int it=n;
		for(int i=n;i>=1;i--){
			while(x[it]-x[i]>d) it--;
			nxt[i]=it;
			// cout<<i<<" "<<nxt[i]<<endl;
			if(nxt[i]!=i){
				e[nxt[i]].pb(i);
			}
			if(nxt[i]==i) nxt[i]=0;
		}
		for(int i=n;i>=1;i--){
			if(nxt[i]==0) dfs(i);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}