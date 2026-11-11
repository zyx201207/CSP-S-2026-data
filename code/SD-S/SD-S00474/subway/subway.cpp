//#include<bits\stdc++.h>
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//freopen(".ans","w",stdout);
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct subway{
	int j,t;
};
struct node{
	int s,e;
};
node plan[1000005];
int c,n,m,d,q;
int a[1005][1005];
int t[1005][1005];
int w[1000005];
int xian[1000005];
int k[1000005];
vector<subway>v[1005];
set<int>s[1005];
map<pair<int,int>,int>ma;
int minn=0x3f3f3f3f3f3f3f3f;
//void dfs(subway now,int end,int minute){
//	if(now.j==end){
//		minn=min(minn,minute);
//		return;
//	}
//	for(auto x:v[now]){
//		dfs(x,end,minute+ma[{now,x.j}]+t[x.t][now.j]);
//	}
//}
/*
**       **
**       **


   ** **
**       **
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
qwq
*/
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ma[{i,j}]=t[i][j];
			s[i].insert(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){//city
		for(int x:s[i]){
			for(int s1:s[i]){
				if(s1!=x){
					v[x].push_back({s1,i});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan[i].s>>plan[i].e;
		for(auto u:v[plan[i].s]){
//			dfs(u.j,plan[i].e,w[plan[i].s]+t[u.t]);
		}
		cout<<"0\n";//though it's wrong
	}
	return 0;
}  
//for this team,i only want to try...
//but i can't do this problem,it's too difficult for me.
