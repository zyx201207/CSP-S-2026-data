#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	int j=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		j+=a[i];
	}
	j/=n;
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[i]<a[i-1]){
				int v=a[i-1];
				a[i-1]=a[i];a[i]=v;
			}
		}
	}
	int zx=100000,h;
	for(int i=0;i<n;i++){
		b[i]=abs(j-a[i]);
		if(b[i]<zx){
			zx=b[i];
			h=i;
		}
	}
	int q=0,k;
	for(int i=h;i>=0;i++){
		if(q+b[i]>m){
			k=i;
			break;
		}
		q+=b[i];
	}
	cout<<k-h+1;
	return 0;
}

