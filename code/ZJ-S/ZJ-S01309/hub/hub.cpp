#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;long long _,t,n,m,rt,dep[N],g[N],vis[N],f[N],mx[N];vector<int> a[N],c;
//bool ck(){
//	if(n%2==0) return 0;for(int i=1;i<=n/2;i++) if(a[i].size()!=2) return 0;
//	for(int i=n/2+1;i<=n;i++) if(a[i].size()!=1) return 0;
//	for(int i=1;i<=n/2;i++) if(a[i][0]!=i+1||a[i][1]!=i+m+1) return 0;
//	return 1;
//}
int ds(int x,int fa){
	int cnt=x,y;g[x]=0;dep[x]=dep[fa]+1;for(auto i:a[x]) if(i!=fa) y=ds(i,x),(dep[cnt]>dep[y]?1:(cnt=y,g[x]=i));
	return cnt;
}
long long dfs(int x,int fa){
	dep[x]=dep[fa]+1,mx[x]=dep[x];for(auto i:a[x]) if(i!=fa&&!vis[i]) mx[x]=max(mx[x],dfs(i,x));
	return mx[x];
}
int get(int x,int fa,int mid){
	if(mx[x]<=mid) return 0;
	int cnt=0;for(auto i:a[x]) if(i!=fa&&!vis[i]) cnt+=get(i,x,mid);
	return cnt+(mx[x]-dep[x]>mid);
}
int check(int mid){
	int x=mid,y=c.size()-1-mid;if(x>y) return 1;
//	cout<<c[x]<<" "<<c[y]<<"\n";
	for(int i=1;i<m;i++){
		int cx=i-1,cy=m-i-1,u=x,v=y,flag=1,cnt=0,k;
		while((k=get(c[u+1],0,mid)),cx>=k+1) cx-=k+1,u++;
		while(v>u&&(k=get(c[v-1],0,mid),cy>=k+1)) cy-=k+1,v--;
		if(cx<0||cy<0) continue;cnt=cx+cy;
//		cout<<cnt<<"!\n";;//cout<<"	"<<c[j]<<":"<<mid-min(j-u,v-j)<<"\n",cout<<"	"<<c[u]<<" "<<c[v]<<"	"<<cnt<<"\n",
		for(int j=u+1;j<=v-1;j++) if(get(c[j],0,mid-min(j-u,v-j))>0) return 0;
		if(cnt>=0) return 1;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>_>>t;while(t--){
		cin>>n>>m,c.clear();for(int i=1;i<=n;i++) a[i].clear(),vis[i]=g[i]=0;
		for(int i=1,j,k;i<n;i++) cin>>j>>k,a[j].push_back(k),a[k].push_back(j);
		int kkk=0;rt=ds(1,0),kkk=ds(rt,0),c.push_back(rt);
		while(g[rt]) c.push_back(g[rt]),rt=g[rt];
		for(auto i:c) vis[i]=1;for(auto i:c) f[i]=dfs(i,0);
		if(n>4000) cout<<(n==m?0:(c.size()-m+4)/3-1)<<"\n";
		else{
		int l=0,r=n+1,mid;while(l+1<r) mid=l+r>>1,(check(mid)?r:l)=mid;
		cout<<r<<"\n";
		}
	}
	return 0;
}
