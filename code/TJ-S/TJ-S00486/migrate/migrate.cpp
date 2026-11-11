#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=2000005;

int n,d;
int a[N];
int cnt;
vector<int>g[N];

void init(){
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	cnt=0;
	return ;
}

int tmp;
int tmpp;
void dfs(int x,int cst,int y){
	if(x==y){
		tmp=min(tmp,cst);
		return ;
	}
	for(auto v:g[x]){
		dfs(v,cst+1,y);
	}
	return ;
}

void dfs2(int x,int cst,int y){
	if(cst>tmp || tmpp>2) return ;
	if(x==y){
		if(cst==tmp) tmpp++;
		return ;
	}
	for(auto v:g[x]){
		dfs2(v,cst+1,y);
	}
	return ;
}

bool check(int x,int y){
	tmp=INT_MAX;
	tmpp=0;
	dfs(x,0,y);
	//cout<<x<<" "<<y<<" "<<tmp<<" ";
	dfs2(x,0,y);
	//cout<<tmpp<<endl;
	if(tmpp==2) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		init();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) {
				if(a[j]-a[i]<=d) g[i].push_back(j);//´æ±àºÅ
				else break;
			}
		}
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++){
				if(check(i,j)) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
