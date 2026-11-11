#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	int k=a[1],maxx=-9999999,maxa=-9999999;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		k&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		cout<<k;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) maxa=max(maxa,a[i]&a[j]);
	}
	cout<<maxa;
	return 0;
}
