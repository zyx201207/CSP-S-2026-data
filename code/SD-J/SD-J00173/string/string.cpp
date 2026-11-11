#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<=r){
		int g=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=g;
		a[l]-=g,a[r]-=g;
		if(a[l]==0)l++;
		else r--;
	}
	cout<<ans;
	return 0;
}
