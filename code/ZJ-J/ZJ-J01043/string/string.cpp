#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010];
char ch[200010];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		while(l<r&&a[l]==0)l++;
		while(l<r&&a[r]==0)r--;
		if(l>=r)break;
		if(ch[l]!=ch[r])ans+=min(a[l],a[r])*1ll;
		int tmp=min(a[l],a[r]);
		a[l]-=tmp;
		a[r]-=tmp;
	}
	cout<<ans;
	return 0;
}
