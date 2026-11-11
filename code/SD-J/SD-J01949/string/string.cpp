#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
				
			}
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			l++;r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
