#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,n,m,x,r=1;
	int y[100005];
	for(int i=1;i<=n;i++){
		y[i]=0;
	}
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n-1;i++){
		cin>>y[i];
		m=m-i*max(y[i],x)+i*min(x,y[i]);
		if(m>=0){
		r++;
		x=y[i];}
		if(m<0)
		break;}
	cout<<r;
	return 0;
}
