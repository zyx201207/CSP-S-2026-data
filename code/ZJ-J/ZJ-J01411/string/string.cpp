#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],res,ans,l,r;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else if(a[r]<a[l]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			l++;r--;
		}
	}
	cout<<ans;
}
