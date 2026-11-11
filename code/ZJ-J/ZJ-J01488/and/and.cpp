#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200000+10];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			
			
			int p=pow(2,30)-1;
			ans=max(ans,(p&a[i]));
		}
	}else if(m==n){
		for(int i=1;i<n;i++){
			ans=ans+(a[i]&a[i+1]);
		}
	}else{
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		ans=maxn;
	}
	cout<<ans<<endl;
	return 0;
}
