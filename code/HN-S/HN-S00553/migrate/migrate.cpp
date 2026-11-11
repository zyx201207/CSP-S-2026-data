#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
const int NR=2e6+5;
int n,d,x[NR],c,t,L[NR],R[NR],cnt[NR],L_1[NR],L_2[NR],r_3[NR],r_2[NR],r_1[NR],dep_1[NR],dep_2[NR];
vector<int>E[NR];
int ans=0;
int fa[NR];
int find(int x) {
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void P1() {
	cin>>n>>d;
	rep(i,1,n)cin>>x[i];
	rep(i,1,n)E[i].clear();
	L[n+1]=0;
	per(i,n,1) {
		L[i]=min(i,L[i+1]);
		while(L[i]-1>=1&&x[i]-x[L[i]-1]<=d) --L[i];
	}
	R[0]=0;
	rep(i,1,n) {
		R[i]=max(i,R[i-1]);
		while(R[i]+1<=n&&x[R[i]+1]-x[i]<=d) ++R[i];
		E[R[i]].push_back(i);
	}
	rep(i,1,n) fa[i]=i;
}
int Visen[NR],now[NR],ois[NR];
void Dfs(int l) {
	ois[l]=1;
		int x=r_1[l];
		int g=R[r_1[l]],h=R[l],w=R[r_2[l]];
		
		int val=0;
		if(h<g) {
			val+=dep_2[l]-dep_2[r_1[l]];
			if(Visen[l]) {
				val+=Visen[l];
			}
		}
		if(now[r_1[l]]>l&&Visen[now[r_1[l]]]) r_3[l]=r_1[l];
		if(r_3[l]!=r_1[l]) {
			if(g<w) {
				val+=dep_1[g]-dep_1[w];
			}
		}
		ans+=val;
		for(int v:E[l]) {
			now[l]=v;
			if(v!=l)
			Dfs(v);
		}
}
void P3() {

	per(i,n,1) {
		ois[i]=0;
		Visen[i]=0;
		fa[i]=find(R[i]);
		dep_1[i]=dep_2[i]=0;
		L_1[i]=L_2[i]=0;
	}
	rep(i,1,n) {
		if(R[i]!=i) {
			if(i>=2)L_1[i]=max(R[i-2],i); else L_1[i]=i;
			if(i>=1)
				L_2[i]=max(R[i-1],i); else L_2[i]=i;
		}
	}
	rep(i,1,n)r_3[i]=r_2[i]=r_1[i]=find(i);
	per(i,n,1) {
		if(i^R[i]) {
			dep_1[i]=dep_1[R[i]]+(R[i]-L_2[i]);
			if(R[i-1]<R[i]-1) {
				dep_2[i]=dep_2[R[i]]+(L_2[R[i]]-L_1[R[i]]);
			} else {
				dep_2[i]=dep_2[R[i]];
				Visen[i]=(L_2[R[i]]-L_1[R[i]]);
			}
			if(i==1)continue;
			int flag=1;
			if(L_1[i]>=R[i]) {
				flag=3;
			} else if(L_2[i]>=R[i]) {
				flag=2;
			}
			//cout<<i<<"->"<<R[i]<<':'<<flag<<'\n';
 			for(int j:E[i]) {
				if(j!=i) {
					r_2[j]=r_2[i],r_1[j]=r_1[i],r_3[j]=r_3[i];
					if(flag==3) {
						r_2[j]=r_1[j];
						r_1[j]=min(r_1[j],i);
						r_3[j]=min(r_3[j],i);
					} else if(flag==2) {
						r_2[j]=r_1[j];
						r_1[j]=min(r_1[j],i);
					}
				}
			}
		}
	}
	ans=0;
	rep(r,1,n) {
		if(find(r)==r) {
			Dfs(r);
		}
	}
	cout<<ans<<'\n';
}
void work() {
	P1();
	P3();
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		work();
	}
	return 0;
}