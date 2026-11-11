#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r])
				a[r]-=a[l],l++;
			else if(a[l]>a[r])
				a[l]-=a[r],r--;
			else l++,r--;
		}else if(a[l]<a[r]){
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			ans+=a[l];
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
