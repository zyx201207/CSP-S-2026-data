#include<bits/stdc++.h>
using namespace std;
int n,m,maxa;
int a[2000009];
int ad(int f1,int f2){
	return (f1&f2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<i;j++){
			if(ad(a[i],a[j])>maxa){
				maxa=ad(a[i],a[j]);
			}
			cout<<ad(a[i],a[j])<<endl;
		}
	}
	cout<<maxa;
	return 0;
}
