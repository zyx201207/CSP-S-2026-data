#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	long long a[50000],b[100000],h=0,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			h++;
			if(a[i]-a[j]<0){
				b[h]=a[j]-a[i];
			}else{
				b[h]=a[i]-a[j];
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=i+1;j<=h;j++){
			if(b[i]>b[j]){
				int o=b[j];
				b[j]=b[i];
				b[i]=o;
			}
		}
	}
	for(int i=0;i<h;i++){
		if(t>m){
			cout<<i-2;
			break;
		}
		t+=b[i];
	}
	return 0;
}

