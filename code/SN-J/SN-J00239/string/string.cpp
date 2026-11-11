#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		len+=1ll*a[i];
	}
	ll lenl=0,lenr=min(a[n]*1ll,len/2);
	ll nowl=0,nowr=n;
	ll nlenl=0,nlenr=min(a[n]*1ll,len/2);
	char cl,cr=c[n];
	ll cnt=0;
	while(1){
		if(lenl==len/2&&lenr==len/2) break;
		while(lenl<=lenr){
			if(lenl==len/2&&lenr==len/2) break;
			ll need=min(a[++nowl]*1ll,len/2-lenl);
			cl=c[nowl];
			lenl+=need;
			cout.flush();
			if(cl!=cr) cnt+=min(need,nlenr);
			nlenl=lenl-lenr;
			nlenr=lenr-lenl;
		}
		while(lenr<lenl){
			if(lenl==len/2&&lenr==len/2) break;
			ll need=min(a[--nowr]*1ll,len/2-lenr);
			cr=c[nowr];
			lenr+=need;
			cout.flush();
			if(cl!=cr) cnt+=min(need,nlenl);
			nlenl=lenl-lenr;
			nlenr=lenr-lenl;
		}
	}
	cout << cnt;
	return 0;
}

