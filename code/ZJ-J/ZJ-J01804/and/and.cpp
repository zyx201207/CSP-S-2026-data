#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],j=1;
int f(int p,int q){
	if(q==0){
		return a[p-1];
	}
	int x=0,y=0;
	for(int i=p;i<=n;i++){
		x=a[i]&f(i+1,q-1);
		y=max(x,y);
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(1,m);
	return 0;
}
