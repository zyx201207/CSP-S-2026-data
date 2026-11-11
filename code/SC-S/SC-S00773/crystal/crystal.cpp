#include <bits/stdc++.h>
using namespace std;
#define int long long
#define a first
#define b second 
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn],op=1,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	ans=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(ans!=a[i+1]-a[i]){
			op=0;
		}
	}
	if(op){
		m/=ans;
		ans=0;
		int cnt=1;
		for(int i=1;i<=n;i++){
			if(ans+i<=m){
				ans+=i;
				cnt++;
			}else{
				cout<<cnt;
				return 0;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]*(j-i)-(s[j-1]-s[i-1])<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}