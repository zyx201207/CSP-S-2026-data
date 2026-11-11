#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll ans=0;
	for(int l=1,r=n;l<=r;){
		if(a[l]>=a[r]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}

