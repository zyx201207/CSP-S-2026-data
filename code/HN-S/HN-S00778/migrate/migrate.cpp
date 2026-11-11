#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5; 
/*
简化提意：给定n个点,两点可直接飞过距离d,求在一条联通的链中
多少中最短路走法 
*/
int c,t,n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((j-i)/d>0&&(j-i)%d>0)ans++;						
			}
		}
		cout<<ans; 
	}
	return 0;
}

