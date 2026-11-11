#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+10;
int c,t,n,d,a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (c==11 || c==12){
			int st=a[2]-a[1];
			int k=d/st;
			if (k==1){
			cout<<0;
			}
			else{
				int p=upper_bound(a+1,a+1+n,d+a[1])-a-1;
			cout<<max(0LL,n-(p+k-1)+1)<<"\n";
			}
			
		}
	}
	
	return 0;
}
