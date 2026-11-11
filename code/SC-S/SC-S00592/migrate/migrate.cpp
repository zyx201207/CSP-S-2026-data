#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int dy[2000005],cnt=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>dy[i];
		}
		sort(dy+1,dy+n+1);
		for(int i=4;i<=n;i++){
			if(dy[i-1]-dy[i-3]<=m&&dy[i]-dy[i-2]<=m&&dy[i]-dy[i-3]>=m){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}