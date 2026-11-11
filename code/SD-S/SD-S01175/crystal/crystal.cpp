#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(l<i&&a[i]*(i-l)-s[i]+s[l]>m)l++;
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}

