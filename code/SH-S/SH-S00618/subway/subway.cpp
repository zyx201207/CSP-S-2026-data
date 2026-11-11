#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int lx[510][500010];
int sj[500010];
int ans=0;
void dfs(int start,int end,int xl){
	for(int i=1;i<=n;i++){
		if(i==xl) continue;
		if(lx[i][start]!=0 && lx[i][end]!=0){
			ans+=lx[i][start]+lx[i][end]+lx[xl][start];
			return;
		}
		else if(lx[i][start]!=0){
			for(int j=1;j<=m;j++){
				if(lx[i][j]!=0 && j!=start){
					ans+=lx[i][j];
					dfs(j,end,i);
					ans-=lx[i][j];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sj[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			lx[i][a]=t;
		}
	}
	for(int i=0;i<q;i++){
		int start,end;
		cin>>start>>end;
		ans+=sj[start]+sj[end];
		dfs(start,end,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
