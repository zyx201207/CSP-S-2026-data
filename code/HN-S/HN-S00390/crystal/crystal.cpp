#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool b=1;
	for(int i=1;i<n;i++){
		b=(a[i+1]-a[i]==a[2]-a[1]);
	}
	if(b==1){
		int c=a[2]-a[1];
		m/=c;
		int ans=(-1+sqrt((1+8*m)*1.0))*1.0/2;
		cout<<ans;
	}
 return 0;
}
