#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if (j-i==3&&a[j]-a[i]==d+1) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

