#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long qz=1,hh=1,hz,tt,ans;
char c[200005];
void mm(){
	if(qz<hz){
		int zj=min(a[qz]-hh+1,tt);
		if(c[qz]!=c[hz]){
			ans+=zj;
		}
		hh+=zj;
		tt-=zj;
	}else{
		if(c[qz]!=c[hz]) ans++;
		hh++,tt--;
	}
	if(hh>a[qz]) hh-=a[qz],qz++;
	if(tt<1) hz--,tt+=a[hz];
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	tt=a[n];
	hz=n;
	if(n%2==0){
		while(qz<hz){
			mm();
		}
	}else{
		while(qz<hz or hh<tt){
			mm();
		}
	}
	cout<<ans;
	return 0;
}
