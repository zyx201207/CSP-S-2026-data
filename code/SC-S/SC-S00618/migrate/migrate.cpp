#include<bits/stdc++.h>
using namespace std;
int a[5005],minn=2e9,cnt=0,n,d;
void dfs1(int x,int mb,int step){
	if(x==mb){
		minn=min(minn,step);return;
	}
	for(int i=mb;i>x;i--){
		if(a[i]-a[x]<=d) dfs1(i,mb,step+1);
	}
}
void dfs2(int x,int mb,int step){
	if(x==mb){
		if(step==minn) cnt++;return;
	}
	for(int i=x+1;a[i]-a[x]<=d,i<=n;i++) dfs2(i,mb,step+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int sc=0;cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				minn=2e9,cnt=0;
				dfs1(i,j,0);
				dfs2(i,j,0);
				if(cnt==2) sc++;
			}
		}
		cout<<sc<<"\n";
	}
	return 0;
} 