#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int ans=0;
	for(int l=1,r=n;l<r;l++){
		while(a[r]<=a[l]&&l<r){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r],r--;
		}
		if(l<r&&c[l]!=c[r]) ans+=a[l];
		a[r]-=a[l];
	}
	cout<<ans;
	return 0;
}