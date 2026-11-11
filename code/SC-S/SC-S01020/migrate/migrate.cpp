#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int minn=0x3f3f3f3f;
int m[2000005];
bool ff;
void dfs(int root , int end , int l , int d , int f){
	if(ff){
		return ;
	}
	if(f>50){
		ff=1;
		return ;
	}
	if(d>=minn){
		return ;
	}
	if(root==end+1){
		minn=min(minn,d);
		m[minn]++;
	}
	for(int i=1;i<=l;i++){
		dfs(root+l,end,l,d+l,f+1);
	}
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset (m,0,sizeof(m));
		minn=0x3f3f3f3f;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ff=0;
		dfs(1,n,d,0,0);
		if(minn==0x3f3f3f3f){
			cout<<0<<endl;
			continue;
		}
		cout<<m[minn]<<endl;
	}
	return 0;
}