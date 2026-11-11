#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll len,a[200010],n,l=1,r,ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}r=n;
	while (l<=r){
		if (a[l]>a[r]){
			if (c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if (a[r]==a[l]){
			if (c[l]!=c[r]){
				ans+=a[r];
			}l++;
			r--;
		}else{
			if (c[l]!=c[r]){
				ans+=a[l];
			}a[r]-=a[l];
			l++;
		}
	}cout<<ans<<"\n";
	return 0;
}

