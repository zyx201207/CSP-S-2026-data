#include<bits/stdc++.h>
using namespace std;
long long n,m,a[611111],ans;
char c[611111];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r) {
		long long temp=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=temp;
		a[l]-=temp;
		a[r]-=temp;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}cout<<ans;
	return 0;
}
