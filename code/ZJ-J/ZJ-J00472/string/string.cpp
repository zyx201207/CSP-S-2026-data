#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,ans=0,c[N],i=1;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(;i<=n;i++) cin>>c[i]>>a[i];
	ll l=1,r=n;
	while(l<=r){
		if(c[l]>c[r]){
			if(a[l]!=a[r]) ans+=c[r];
			c[l]-=c[r];
			r--;
		}
		else if(c[l]==c[r]){
			if(a[l]!=a[r]) ans+=c[r];
			l++,r--;
		}
		else{
			if(a[l]!=a[r]) ans+=c[l];
			c[r]-=c[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
