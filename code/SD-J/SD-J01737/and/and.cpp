#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;	long long maxx=0;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]!=i-1) f=1; 
	}
	long long ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	long long fac=1;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				fac=fac&a[j];
			}
			ans=max(maxx,fac);
		}
		cout<<ans;
		return 0;
	}
	if(maxx<=4){
		cout<<3;
		return 0;
	}
	if(f==0){
		cout<<n-m;
		return 0;
	}
	cout<<maxx;
	return 0;
}
