#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxq=1e5+7;
const int maxk=5e5+7;
vector<int>t[maxn],a[maxn],k[maxn];
int c,n,m,d,q,s,z,w[maxq];
bool check(int l,int A){
	for(int i=0;i<a[l].size();++i){
		if(a[l][i]==A){
			return 1;
		}
	}
	return 0;
}
int bfs(int x,int ans){
	queue<int>op;
	op.push(x);
	while(!op.empty()){
		int len1=a[x].size();
		for(int i=0;i<len1;++i){
			int len2=k[i].size();
			for(int j=0;j<len2;++j){
				if(check(j,z)==1){
					return ans+t[z][j];
				}
				ans=bfs(j,ans+t[j][i]);
				if(op.empty()) return -1;
				op.pop();
			} 
		}
	}
	return -1;
}
int ans=0;
void dfs(int x,int res){
	if(check(x,z)){
		ans=res+t[z][x];
		return ;
	}
	int len1=a[x].size();
	for(int i=0;i<len1;++i){
		int len2=k[i].size();
		for(int j=0;j<len2;++j){
			dfs(j,res+t[j][i]);
		} 
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		int b;
		cin>>b;
		for(int j=1;j<=b;++j){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			k[x].push_back(i);
			t[i].push_back(y);
		}
	}
	while(q--){
		cin>>s>>z;
		int minn=1e8;
		for(int i=0;i<k[s].size();++i){
		bfs(k[s][i],0);
			minn=min(minn,ans);
		}
		cout<<minn<<endl; 
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
