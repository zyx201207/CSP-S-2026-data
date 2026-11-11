#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<i&&a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
		if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m)ans=max(1ll*i-j+1,ans); 
	}
	cout<<ans;
	return 0;
}
