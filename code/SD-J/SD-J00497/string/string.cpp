#include<bits/stdc++.h>

#define int long long

using namespace std;

int n;
int a[200005];
char c[200005];
int ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int l=1,r=n;l<r;){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else l++,r--;
		}
		else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
