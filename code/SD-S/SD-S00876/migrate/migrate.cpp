#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,t,c,d,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;(long long)(i+2*d-1)<=n;i++){
			int pos=lower_bound(a+1,a+n+1,(long long)2*d-1+a[i])-a;
			if(a[pos]==(long long)(a[i]+2*d-1)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
