#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],s[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];
		while(ans<i){
			if(a[i]*(ans+1)-(s[i]-s[i-ans-1])<=m)ans++;
			else break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
