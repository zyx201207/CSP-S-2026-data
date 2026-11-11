#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		maxa=a[1]&a[2];
		for(int i=2;i<n;i++){
			maxa=maxa&a[i+1];
		}
		cout<<maxa;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			if(maxa<a[i]){
				maxa=a[i];
			}
		}
		cout<<maxa;
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]&a[i+1]>maxa){
				maxa=a[i]&a[i+1];
			}
		}
		cout<<maxa;
	}
	return 0;
}
