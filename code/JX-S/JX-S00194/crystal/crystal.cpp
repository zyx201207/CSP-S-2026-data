#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans,las=1;
ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int j=las;
		while(j<=n){
			ll sum=s[j]-s[i-1];
			if(a[j]*(j-i+1)-sum>m){
				las=j-1;
				ans=max(ans,j-i);
				break;
			}
			if(j==n) ans=max(ans,j-i+1),las=n+1;
			j++;
		}
	}
	cout<<ans;
	return 0;
}
