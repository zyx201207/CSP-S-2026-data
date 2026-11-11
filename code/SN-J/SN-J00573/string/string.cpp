#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;l<=r;){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]!=a[r]){
			if(a[l]>a[r]) a[l]-=min(a[l],a[r]),r--;
			else a[r]-=min(a[l],a[r]),l++;
		}else l++,r--;
	}
	cout<<ans;
	return 0;
}
