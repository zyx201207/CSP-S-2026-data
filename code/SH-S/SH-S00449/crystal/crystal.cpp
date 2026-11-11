#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int j=1;
	long long c=0;
	for(int i=1;i<=n;i++){
		c+=(i-j)*(a[i]-a[i-1]);
		while(c>m)c-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

