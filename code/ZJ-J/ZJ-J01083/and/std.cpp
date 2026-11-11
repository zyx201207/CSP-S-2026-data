#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mm(int u){
	long long p=1;
	for(int i=1;i<=u;i++) p*=2;
	return p;
}
int a[200005],b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int jj=1;
		while(a[i]/mm(jj)!=1) jj++;
		c[i]=jj;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}if(m==n-1){
		long long x=a[1],y=a[2];
		for(int i=2;i<n;i++) x&=a[i];
		for(int i=3;i<=n;i++) y&=a[i];
		cout<<max(x,y);
		return 0;
	}
	
	return 0;
}
