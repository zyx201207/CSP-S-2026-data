#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long a[5005]={0};
	long long b[5005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]){
				b[i]=b[i]+a[i]-a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>m){
			b[i]=0;
		}
	}
	int t=0,q=0,p=0;
	for(int i=1;i<=n;i++){
		if(b[i]>=t){
			t=b[i];
			q=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=a[q]){
			p++;
		}
	}
	cout<<p;
	return 0;
}
