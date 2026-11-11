#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,m,n,d,q,top,ans,num;
int a[500005];
int dis[500005],siz[500005],dj[500005];
vector<int> s[1000005];
void djs(int rt){//No
	num=0;
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
			int to=s[x][i];
			if(dis[x]+to<=dis[to]){
				if(dis[x]+to==dis[to]) 
					num++;
				dis[to]=dis[x]+to;
				dj[++tail]=to;
			}
		}
	}
}
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		s[x].push_back(y);
		s[y].push_back(x);
	}
}
void work(){
	djs(1);
	cout<<num<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>q;
	while(q--){
		init();
		work();
	}
	return 0;
}
