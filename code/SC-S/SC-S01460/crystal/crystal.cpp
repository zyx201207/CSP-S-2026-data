#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[500005],m,ans,f=0,f1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=1;
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1])f1=1;
	}
	if(f1==0){
		int zh=0;
		for(int i=1;i<=n-1;i++){
			zh=(1+i)*i/2*(a[2]-a[1]);
			if(zh>m){
				cout<<i;
				return 0;
			}
		}
	} 
	else if(f==0){
		int zh=0;
		for(int i=1;i<=n-1;i++){
			zh+=i;
			if(zh>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int zh=0;
		for(int j=i-1;j>=1;j--){
			zh+=a[j];
			if((i-j)*a[i]-zh<=m)ans=max(ans,i-j);
		}
	}
	cout<<ans+1;
	return 0;
}