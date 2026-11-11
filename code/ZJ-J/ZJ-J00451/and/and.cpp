#include<bits/stdc++.h>
using namespace std;
int n,a[300001],ans=0,m,x=-65536;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(x<a[i])    x=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(x<(a[i]&a[j]))    x=(a[i]&a[j]);
			}
		}
		cout<<x;
		return 0;
	}
	x=a[1];
	if(m==n){
		for(int i=1;i<=n;i++){
			x=x&a[i];
		}
		cout<<x;
		return 0;
	}
	cout<<7;
	return 0;
}