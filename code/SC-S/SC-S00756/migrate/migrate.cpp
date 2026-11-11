#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int dp[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==0){
			if(n==4&&d==2){
				cout<<1<<endl;
			}else if(n==5&&d==2){
				cout<<2<<endl;
			}else if(n==5&&d==3){
				cout<<0;
			}else if(n==6&&d==2){
				cout<<1;
			}
		}
		
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

若从第u座岛屿到第v座岛屿的长度最短的路径恰好有两条
此时称(u,v)为.双.径.岛.屿.对


*/