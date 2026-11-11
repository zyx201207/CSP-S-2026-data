#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[2005][32],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ans,mx=0,ppp=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ppp=max(ppp,a[i]);
	}if(n==1){
		cout<<ppp;
		return 0;
	}
	return 0;
}
