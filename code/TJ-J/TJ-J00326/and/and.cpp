#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	int m,n,maxx=-12;
	cin>>n>>m;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n-1;i++){
		
		if(a[i]!=a[i+1]){
			flag=true;
		}
	}
	if(flag==false){
		cout<<a[1];
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	return 0;
}
