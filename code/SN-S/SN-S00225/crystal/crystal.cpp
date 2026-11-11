#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
long long w[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		
		c[i-1]=a[i]-a[i-1];
	}
	w[1]=0;
	for(int i=2;i<=n;i++){
		w[i]=c[i-1]*(i-1)+w[i-1];
	}
	

	for(int i=1;i<=n;i++){
		if(w[i]>m){
			cout<<i-1;
			break;
		}
	}
	
	return 0;
}
