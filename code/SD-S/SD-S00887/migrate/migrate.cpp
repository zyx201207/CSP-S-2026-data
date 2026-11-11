#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,xx[1000006],cnt,bs[1005][1005],cs[1004][1004];
void dfs(int st,int x,int y,int z){
	if(x==y){
		if(bs[st][y]==z) cs[st][y]++;
		if(bs[st][y]>z){
			cs[st][y]=1;
			bs[st][y]=z;
		}
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(xx[i]-xx[x]<=d){
			dfs(st,i,y,z+1);
		}
		else break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(cs,0,sizeof(cs));
		memset(bs,127,sizeof(bs));
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>xx[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,i,j,0);
				if(cs[i][j]==2){
				    cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
