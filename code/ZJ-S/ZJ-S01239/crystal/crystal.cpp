#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(s[i]-s[j-1]+m>=a[i]*(i-j+1)){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
} 
