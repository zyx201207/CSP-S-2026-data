#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
//Ò»ÂÌÈýºÚ 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,cnt=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt=a[i]-a[i-1];
		}
		//cout<<(n/d-cnt)*2-1; 
		cout<<ceil(n*1.0/(d+2*1.0))<<"\n";
	}
	return 0;
}
