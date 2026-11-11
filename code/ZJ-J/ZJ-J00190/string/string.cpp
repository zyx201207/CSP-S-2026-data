#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,L;char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	int l=1,r=n,nwl=1,nwr=1;
	while(l<r){
		int shl=a[l]-nwl+1,shr=a[r]-nwr+1;
		if(shl>=shr){
			ans=ans+(c[l]==c[r]?0:shr);
			if(shl==shr){
				++l;--r;
				nwl=nwr=1;
			}else{
				--r;
				nwl+=shr;
				nwr=1;
			}
		}else{
			ans=ans+(c[l]==c[r]?0:shl);
			++l;
			nwr+=shl;
			nwl=1;
		}
	}
	cout<<ans;
	return 0;
}