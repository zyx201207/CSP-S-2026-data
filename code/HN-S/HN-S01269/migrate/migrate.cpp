#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int to,v;
};
int t,m,n,d,q,top,ans;
int a[500005];
int dis[500005],siz[500005],dj[500005];
int num[100005];
vector<node> s[500005];
void djs(int rt){
	memset(num,0,sizeof(num));
	memset(dis,13,sizeof(dis));
	memset(siz,0,sizeof(siz));
	int head=1,tail=1;
	dj[tail]=rt;
	dis[rt]=0;
	while(head<=tail){
		int x=dj[head];
		head++;
		if(siz[x]) continue;
		siz[x]=1;
		for(int i=0;i<s[x].size();i++){
			node to=s[x][i];
			if(dis[x]+to.v<=dis[to.to]){
				if(dis[x]+to.v==dis[to.to]) 
					num[to.to]++;
				dis[to.to]=dis[x]+to.v;
				dj[++tail]=to.to;
			}
		}
	}
}
void init(){
	top=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=top;j++){
			if(x-a[j]>m) continue;
			s[i].push_back({j,x-a[j]});
			s[j].push_back({i,x-a[j]});
		}
		a[++top]=x;
	}
}
void work(){
	ans=0;
	for(int i=1;i<=n;i++){
		djs(i);
		for(int i=1;i<=n;i++)
			if(num[i]==2) 
				ans++;
	}
	cout<<ans+1<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>q;
	while(q--){
		init();
		work();
	}
	return 0;
}
