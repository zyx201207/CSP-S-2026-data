#include<bits\stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+9;
int T,n,m,d,q,f[N],qe[N],b[N],b1[N],w1[N],c[N],c1[N];
int fst[N],ne[N],to[N],w[N],tot;
struct node{
	int x,id;
	bool operator < (const node &y)const{
		return y.x<x;
	}
};
void add(int x,int y,int z){
	ne[++tot]=fst[x];
	fst[x]=tot;
	w[tot]=z;
	to[tot]=y;
//	cout<<x<<" "<<y<<" "<<z<<"\n";
}
void dij(int s){
	
	for(int i=1;i<=m;i++)f[i]=2e9+9,qe[i]=0;
	f[s]=0;
	priority_queue<node>q;
	q.push({0,s});
//	cout<<s<<":\n";
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(qe[x])continue;
		qe[x]=1;
		for(int i=fst[x];i;i=ne[i]){
			int y=to[i];
			if(qe[y])continue;
			if(f[x]+w[i]<f[y]){
				f[y]=f[x]+w[i];
				q.push({f[y],y});
//				cout<<f[x]<<" "<<w[i]<<" "<<y<<" "<<f[y]<<"\n"; 
			}
		}
	} 
//	FOR(i,1,m)cout<<f[i]<<" ";
//	cout<<"\n";
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>T>>n>>m>>d>>q;
//	cout<<((node){n,m}<(node){d,q});
	if(T!=20&&T!=21){
		for(int i=1;i<=m;i++)cin>>w1[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)cin>>b[j]>>b1[j];
			for(int i1=1;i1<=k;i1++)
			for(int j=1;j<i1;j++){
				add(b[i1],b[j],b1[i1]+b1[j]);
				add(b[j],b[i1],b1[i1]+b1[j]);
			}
		}
		for(int i=1;i<=q;i++){
			int a,b2;
			cin>>a>>b2;
			dij(a);
			cout<<f[b2]+w1[a]+w1[b2]<<"\n";
		}
	}
	if(T==20||T==21){
		for(int i=1;i<=m;i++)cin>>w1[i];
		int k1,k2;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			int x;
			cin>>x;
			cin>>b1[x];
			b[x]=1;
		}
		cin>>k2;
		for(int j=1;j<=k2;j++){
			int x;
			cin>>x;
			cin>>c1[x];
			c[x]=1;
		}
		for(int i=1;i<=q;i++){
			int a,b2;
			cin>>a>>b2;
			if(b[a]&&b[b2]){
				if(c[a]&&c[b2])cout<<w1[a]+w1[b2]+min(b1[a]+b1[b2],c1[a]+c1[b2])<<"\n";
				else if(!c[a]&&!c[b2])cout<<w1[a]+w1[b2]+b1[a]+b1[b2]<<"\n";
				else if(c[a]){
					int ans=2e9+9;
					FOR(i,1,m){
						if(b[i]&&c[i])ans=min(ans,c1[a]+c1[i]+b1[i]+b1[b2]);
					}
					cout<<min(w1[a]+w1[b2]+ans,w1[a]+w1[b2]+b1[a]+b1[b2])<<"\n";
				}else{
					int ans=2e9+9;
					FOR(i,1,m){
						if(b[i]&&c[i])ans=min(ans,b1[a]+b1[i]+c1[i]+c1[b2]);
					}
					cout<<min(w1[a]+w1[b2]+ans,w1[a]+w1[b2]+b1[a]+b1[b2])<<"\n";
				}
			}else if(c[a]&&c[b2]){
				if(!b[a]&&!b[b2])cout<<w1[a]+w1[b2]+c1[a]+c1[b2]<<"\n";
				else if(b[a]){
					int ans=2e9+9;
					FOR(i,1,m){
						if(b[i]&&c[i])ans=min(ans,b1[a]+b1[i]+c1[i]+c1[b2]);
					}
					cout<<min(w1[a]+w1[b2]+ans,w1[a]+w1[b2]+c1[a]+c1[b2])<<"\n";
				}else{
					int ans=2e9+9;
					FOR(i,1,m){
						if(b[i]&&c[i])ans=min(ans,c1[a]+c1[i]+b1[i]+b1[b2]);
					}
					cout<<min(w1[a]+w1[b2]+ans,w1[a]+w1[b2]+c1[a]+c1[b2])<<"\n";
				}
			}
			else if(b[a]){
				int ans=2e9+9;
				FOR(i,1,m){
					if(b[i]&&c[i])ans=min(ans,b1[a]+b1[i]+c1[i]+c1[b2]);
				}
				cout<<w1[a]+w1[b2]+ans<<"\n";
			}else{
				int ans=2e9+9;
				FOR(i,1,m){
					if(b[i]&&c[i])ans=min(ans,c1[a]+c1[i]+b1[i]+b1[b2]);
				}
				cout<<w1[a]+w1[b2]+ans<<"\n";
			}
		}
		return 0;
	}
}
