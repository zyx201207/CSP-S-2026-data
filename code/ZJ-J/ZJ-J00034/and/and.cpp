#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+5],mx=-1000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];  
	}
	if(m==2){
	for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	else if(m==n){
		long long zzz=a[1];
		for(int i=2;i<=m;i++){
			zzz&=a[i];
		}
		mx=zzz;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);	
		}
	}
	cout<<mx;
	return 0;
}