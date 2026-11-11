#include<bits/stdc++.h>
using namespace std;
int n,a[200005],hed,til;
long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	hed=1,til=n;
	while(hed<til){
		if(a[hed]<a[til]){
			a[til]-=a[hed];
			if(c[hed]!=c[til]) ans+=a[hed];
			hed++;
		}else if(a[hed]>a[til]){
			a[hed]-=a[til];
			if(c[hed]!=c[til]) ans+=a[til];
			til--;
		}else{
			if(c[hed]!=c[til]) ans+=a[hed];
			hed++,til--;
		}
	}
	printf("%lld",ans);
	return 0;
}