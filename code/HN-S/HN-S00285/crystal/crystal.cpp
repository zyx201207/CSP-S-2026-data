#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,zx=1000000000000,zd=-1000000000000,hh=-1,hhh=0;
	cin>>n>>m;
	if(m==0){
		cout<<"0";
		return 0;
	}
	int aa=0,bb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<zx||i==1)zx=a[i];
		if(a[i]>zd||i==1)zd=a[i];
		if(a[i]!=i&&aa==0)aa=1;
		if(i>=3&&(a[i]-a[i-1])!=(a[i-1]-a[a[i-2]]))bb=1;
	}
	if(aa==0){//A
		for(int i=1;i<=n-1;i++){
			b[i]=b[i-1]+i;
			if(b[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(bb==0){//B
	int r=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			b[i]=b[i-1]+i*r;
			if(b[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	
	
	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j]>a[j+1])swap(a[j],a[j+1]);
		} 
	}
	
	
	for(int u=1;u<=n;u++){//无特殊情况 
		int i=a[u];
		for(int j=1;j<=n;j++){
			b[j]=i-a[j];
		}
		sort(b+1,b+n+1);
		long long sy=m,h=0;
		int wz=1;
		for(int j=1;j<=n;j++){
			if(b[j]<=sy&&b[j]>=0){
				h++;
				sy-=b[j];
			}

		}
		
		if(h>hh)hh=h;
	}
	cout<<hh;
	
	return 0;
} //Oct31==Dec25?
