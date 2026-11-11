#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=(N*N+N)/2;
int e[M],nx[M],h[N],idx=1,c,t,ans;
int n,num[200001],dis[200001],vis[200001];
long long d,a[200001];
void add(int a,int b){
	e[idx]=b;
	nx[idx]=h[a];
	h[a]=idx++;
}
queue<int>q;
void djk(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	num[st]=1;
	while(q.size()){
		int y=q.front();
		q.pop();
		for(int i=h[y];i;i=nx[i]){
			int v=e[i];
			if(dis[v]>dis[y]+1){
				dis[v]=dis[y]+1;
				num[v]=num[y];
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}else if(dis[v]==dis[y]+1){
				num[v]+=num[y];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(h,0,sizeof h);
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)add(i,j);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			djk(i);
			for(int j=i+1;j<=n;j++){
				if(num[j]==2&&dis[j]<0x3f3f3f3f){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}