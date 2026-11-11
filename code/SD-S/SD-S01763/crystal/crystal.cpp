#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10009],b[10009];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	int d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(i<n)d=a[i-1]-a[i];
		b[i]=b[i-1]+a[i];
	}
	if(d!=-1){
		ans=m/d;
		
	cout<<ans+4;
	return 0;}
	for(int w=n;w==1;w--){
		for(int j=1;j<=n;j++){
			int q=w*a[j]-b[j]*b[j-1];
			ans=1;
			break;
		}
	}cout<<ans+4;
	return 0;
} 
