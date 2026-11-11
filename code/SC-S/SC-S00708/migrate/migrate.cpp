#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;

int c,t,n,d;
int a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;bool flg=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flg=0;
		}
		if(d==1){
			cout<<0;
			continue;
		}
		if(flg){
			int ans=0;int md=(a[n]-a[n-1]);
			if(md>d){
				cout<<0;
				return 0;
			}
			int cnt=d/md;
			for(int i=0;i<=n;i++){
				if(i+d*2>n) continue;
				ans++;
			}
			cout<<ans<<"\n";
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

1 
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/