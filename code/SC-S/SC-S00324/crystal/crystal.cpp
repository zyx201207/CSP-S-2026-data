#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);      
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		if(s[i]+m >= (i*a[i])){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}