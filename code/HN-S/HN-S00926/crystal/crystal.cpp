#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool ok1,ok2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (a[i]!=a[i-1]+1) ok1=1;
		if (i>=3){
			if (a[i]-a[i-1]!=a[i-1]-a[i-2]) ok2=1;
		}
	}
	if (!ok1 || !ok2){
		if (n==1){
			cout<<1;
			return 0;
		}
		for (int i=1;i<=n;++i){
			if (m<abs(a[i])){
				cout<<ans;
				return 0;
			}
			else {
				m-=abs(a[i]);
				++ans;
			}
			if (i==n){
				cout<<n;
				return 0;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i){
		
	}
} 
