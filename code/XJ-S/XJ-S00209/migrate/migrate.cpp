#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
long long c,t,n,d,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=d;i++){
			if(n>=2*i/(a[2]-a[1]))ans+=(n-2*i/(a[2]-a[1])+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
