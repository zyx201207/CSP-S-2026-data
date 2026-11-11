#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sz=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sz+=a[i];
	}
	long long ans=0,nl=a[1],nr=a[n],nn=0,lp=1,rp=n;
	while(nn<sz/2){
		nl=min(nl,sz/2-nn);
		if(nl<nr){
			nr-=nl;
			if(b[lp]!=b[rp]){
				ans+=nl;
			}
			nn+=nl;
			nl=a[++lp];
		}
		else if(nl==nr){
			if(b[lp]!=b[rp]){
				ans+=nl;
			}
			nn+=nl;
			nl=a[++lp];
			nr=a[--rp];
		}
		if(nr<nl){
			nl-=nr;
			if(b[lp]!=b[rp]){
				ans+=nr;
			}
			nn+=nr;
			nr=a[--rp];
		}
	}
	cout<<ans;
	return 0;
}
