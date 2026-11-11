#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000100];
char c[1000100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,t=0,mx=0,mn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			mx=max(a[l],a[r]);
			mn=min(a[l],a[r]);
			ans+=mx-t;
		}
		t=mx-mn;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
