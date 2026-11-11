#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,t,n,k,vis[N];
int u[N],v[N],fa[N],d[N],dist[N];
vector<int>V[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return ;
	fa[fx]=fy;
}
void dfs(int u,int f){
	dist[u]=min(dist[u],d[u]);
	for(int v:V[u]){
		if(v==f)continue;
		d[v]=d[u]+1;
		dfs(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	for(;t--;){
		cin>>n>>k;
		if(c<=3){
			int ans=1e9;
			for(int i=1;i<=n;i++)V[i].clear();
			for(int i=1;i<n;i++){
				cin>>u[i]>>v[i];
				V[u[i]].push_back(v[i]);
				V[v[i]].push_back(u[i]);
			}
			for(int S=0;S<(1<<n);S++){
	//			cerr<<S<<'\n';
				if(__builtin_popcount(S)!=k)continue;
				for(int i=1;i<=n;i++)
					if((S>>i-1)&1)fa[i]=i;
				for(int i=1;i<n;i++)
					if(((S>>u[i]-1)&1)&&((S>>v[i]-1)&1))merge(u[i],v[i]);
				for(int i=1;i<=n;i++)vis[i]=0;
				for(int i=1;i<=n;i++)
					if((S>>i-1)&1)vis[find(i)]=1;
				int cnt=0;
				for(int i=1;i<=n;i++)cnt+=vis[i];
				if(cnt>2)continue;
	//			cerr<<S<<"\n";
				for(int i=1;i<=n;i++)dist[i]=1e9;
				for(int i=1;i<=n;i++)
					if((S>>i-1)&1)d[i]=0,dfs(i,0);
				int now=0;
				for(int i=1;i<=n;i++)now=max(now,dist[i]);
				ans=min(ans,now);
			}
			cout<<ans<<'\n';			
		}
		else{
			for(int i=1;i<n;i++){
				cin>>u[i]>>v[i];
			}
			if(k==n){
				cout<<"0\n";
				continue;
			}
			if(k>=n/2){
				cout<<"1\n";
				continue;
			}
			if(k==1){
				int D=(n+1)/2+1;
				cout<<D/2<<'\n';
				continue;
			}
			int D=n/2;
//			cerr<<n<<' '<<D<<'\n';
			int l,r,ans=1e9;
			l=(D-k)/4+k/4;
			r=D-(D-k)/4-k/4;
//			cerr<<l<<' '<<r<<'\n';
			for(int a=k/4-10;a<=k/4+10;a++)
				for(int b=k/4-10;b<=k/4+10;b++)
					for(int c=k/4-10;c<=k/4+10;c++){
						int d=k-a-b-c;
						if(d<0)continue;
						int l1=l-a+1,r1=l+b;
						int l2=r-c+1,r2=r+d;
						if(l1<1||r1>l2||r2>D)continue;
						ans=min(ans,max((l2-r1)/2+1,max(l1,D-r2+1)));
//						if(max((l2-r1)/2+1,max(l1,D-r2+1))==12251)cerr<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<'\n';
					}
			cout<<ans<<'\n';
		}
	}
	return 0;
}