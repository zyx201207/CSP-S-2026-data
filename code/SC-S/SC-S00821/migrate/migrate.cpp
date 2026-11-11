#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k=d/(a[2]-a[1]);
		if(k==0||k==1){
			cout<<0<<endl;
		}
		else cout<<max(0ll,(n-(2*k-1)))<<endl;
	}
	return 0;
}