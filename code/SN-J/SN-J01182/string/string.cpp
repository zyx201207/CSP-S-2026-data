#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n;
char c[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n,ans=0;
	while(l!=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l++];
		}
		else{
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r--];
		}
	}
	cout<<ans;
	return 0;
}
