#include <bits/stdc++.h>
using namespace std;
int n,m,sum,a[200005];
bool cmp(int x,int y){
	int xh=1,xc,yh=1,yc;
	while(1){
		xh*=2;
		if(xh>x){
			xc=xh-x;
			break;
		}
	}
	while(1){
		yh*=2;
		if(xh>x){
			yc=yh-y;
			break;
		}
	}
	return xc<yc;
	
}
bool cnp(int p,int q){
	return p>q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnp);
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
