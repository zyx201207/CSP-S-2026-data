#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;long long ans=0;
	while(l<r){
		int t=min(a[l],a[r]);
		a[l]-=t,a[r]-=t;
		if(c[l]!=c[r])ans+=t;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
