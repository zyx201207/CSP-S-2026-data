#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10;
int c,t,n,d,x[N],f[N],g[N],nxt[N],a[N],b[N],pre[N],pre1[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	int ans=0;
	if(n<=300){
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)f[j]=0,g[j]=0;
			g[i]=1;
			for(int j=i+1;j<=n;++j){
				for(int k=j;k>=i;--k){
					if(x[k]>=x[j]-d)f[j]=f[k]+1;
				}
				int cnt=0;
				for(int k=j;k>=i;--k){
					if(x[k]>=x[j]-d&&f[j]==f[k]+1){
						g[j]+=g[k];
						if(g[j]>2)break;
					}
				}
			}
			for(int j=i+1;j<=n;++j)ans+=(g[j]==2);
		}
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;++i){
		int now=i+1;
		while(now<=n&&x[now]-x[i]<=d)++now;
		--now;
		nxt[i]=now;
	}//可以优化 
	for(int i=1;i<=n;++i){
		int pos=i;
		vector<int>e;
		while(nxt[pos]!=pos)e.emplace_back(pos),pos=nxt[pos];
		e.emplace_back(pos);
		int tot=0;
		for(int j=1;j<e.size()-1;++j){
			int cnt=0;
			if(e[j]-1>e[j-1]&&x[e[j]-1]-x[e[j-1]]<=d&&x[e[j+1]]-x[e[j]-1]<=d)++cnt;
			if(e[j]+1<e[j+1]&&x[e[j]+1]-x[e[j-1]]<=d&&x[e[j+1]]-x[e[j]+1]<=d)++cnt;
			if(e[j]+2<e[j+1]&&x[e[j]+2]-x[e[j-1]]<=d&&x[e[j+1]]-x[e[j]+2]<=d)++cnt;
			if(e[j]-2>e[j-1]&&x[e[j]-2]-x[e[j-1]]<=d&&x[e[j+1]]-x[e[j]-2]<=d)++cnt;
			a[++tot]=cnt;
			b[tot]=e[j];
		}
		b[0]=e[0];
		for(int j=1;j<=tot;++j)pre[j]=pre[j-1]+(a[j]>1),pre1[j]=pre1[j-1]+(a[j]==1);
		for(int j=i+1;j<=e[e.size()-1];++j){
			int l=0,r=tot+1;
			while(l<r-1){
				int mid=l+r>>1;
				if(b[mid]<=j)l=mid;
				else r=mid;
			}
			if(l){
				int cnt=0;
				if(b[l]!=j){
					if(b[l]+1<j&&x[j]-x[b[l]+1]<=d&&x[b[l]+1]-x[b[l-1]]<=d)++cnt;
					if(b[l]-1>b[l-1]&&x[b[l]-1]-x[b[l-1]]<=d&&x[j]-x[b[l]-1]<=d)++cnt;
					if(b[l]+2<j&&x[j]-x[b[l]+2]<=d&&x[b[l]+2]-x[b[l-1]]<=d)++cnt;
					if(b[l]-2>b[l-1]&&x[b[l]-2]-x[b[l-1]]<=d&&x[j]-x[b[l]-2]<=d)++cnt;
				}
				if(pre1[l-1]+(cnt==1)==1&&pre[l-1]+(cnt>1)==0){
					++ans;
				}else{
					if(pre1[l-1]+pre[l-1]>=2)break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

