#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans=1e9;
const int M=5e5+5;
const int N=505;
struct node{
	long long w;
	vector<int> xl;
	vector<long long> tim;
}a[M];
vector<int> v[N];

void dfs(int pos,int ed,long long step){
	if(step>ans){
		return;
	}
	if(pos==ed){
		ans=min(ans,step);
	}
	for(int i=0;i<a[pos].xl.size();i++){
		int x=a[pos].xl[i];
		for(int j=0;j<v[x].size();j++){
			dfs(v[x][j],ed,step);
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].w;
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		long long ai,ti;
		for(int j=1;j<=k;j++){
			cin>>ai>>ti;
			a[ai].xl.push_back(i);
			a[ai].tim.push_back(ti);
			v[i].push_back(ai);
		}
	}
	while(q--){
		ans=1e9;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
	}
	return 0;
}
