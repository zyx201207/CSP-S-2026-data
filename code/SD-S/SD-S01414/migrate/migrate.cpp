#include<bits/stdc++.h>
#define int long long
using namespace std;
//×¢Òâ¶à²âÇå¿Õ 
int n,d;
int a[2000010];
vector<int>v[2000010];
int dis[2000010],is[2000010];
void bfs(int st){
	for(int i=1;i<=n;i++)dis[i]=1e18,is[i]=0;
	queue<int>q;
	dis[st]=0;
	is[st]=1;
	q.push(st);
	while(!q.empty()){
		int t=q.front();q.pop();
		for(auto i:v[t]){
			if(dis[i]>dis[t]+1){
				is[i]=is[t];
				dis[i]=dis[t]+1;
				q.push(i);
			}else if(dis[i]==dis[t]+1){
				is[i]+=is[t];
			}
			
		}
	}
}
int get(int l,int r){
	if(l>r)return l-r;
	else return r-l;
}
void work(){	
	cin>>n>>d;
	for(int i=1;i<=n;i++)v[i].clear(); 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(get(a[i],a[j])>d)continue;
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(is[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--)work();
	
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
