#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[200004];
char c[200004];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		ll shan=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=shan;
		a[l]-=shan;a[r]-=shan;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}

