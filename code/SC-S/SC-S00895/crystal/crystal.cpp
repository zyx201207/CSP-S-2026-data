#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],mc[100010],cs;
int f(int x,int j){
	if(x>m){
		return cs;
	}
	cs++;
	return f(x+(a[j+2]-a[j+1])*cs,j+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int maxed;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n-1;i++){
		cs=1;
		mc[i]=f(a[i+1]-a[i],i);
	}
	maxed=mc[1];
	for(int i=1;i<=n;i++){
		maxed=max(maxed,mc[i]);
	}
	cout<<maxed;
	return 0;
}