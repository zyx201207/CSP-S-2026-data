#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1e2;
int c,n,m,d,q;
int aps[N],a[N],t[N],p[N],used[N],dis[N];
struct cpp{
	int x,y;
};
vector<cpp> l[N];
struct node{
	int di,x;
	bool operator<(const node x)const{
		return x.di<di;
	}
};
priority_queue<node> qs; 
int work(int x,int y){
	memset(aps,63,sizeof(aps));
	memset(used,0,sizeof(used));
	aps[x]=0;
	qs.push({0,x});
	while(!qs.empty()){
		node u=qs.top();
		qs.pop();
		for(int i=0;i<l[u.x].size();i++){
			cpp v=l[u.x][i];
			if(v.y+aps[u.x]<aps[v.x]){
				aps[v.x]=aps[u.x]+v.y;
				if(!used[v.x]){
					qs.push(node{aps[v.x],v.x});
					used[v.x]=1;
				}
			}
		}
	}
	return aps[y];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>p[i];
//	memset(l,63,sizeof(l));
//	l[1].push_back(cpp{1,1});
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=s;j++){
			for(int k=1;k<=s;k++){
				if(j!=k){
					l[a[j]].push_back(cpp{a[k],t[j]+t[k]});
					l[a[k]].push_back(cpp{a[j],t[j]+t[k]});
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<work(x,y)+p[x]+p[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/