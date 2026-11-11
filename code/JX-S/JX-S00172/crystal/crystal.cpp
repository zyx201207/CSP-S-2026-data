#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,b;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int s=a[2]-a[1];
		if(a[i]!=i||a[i]-a[i-1]!=s) k=1;
		x=min(x,a[i]-a[i-1]);
	}
	if(x>m){
		cout<<1;
		return 0;
	 }
	if(x==m){
		cout<<2;
		return 0;
	} 
	int i=1;
	while(m>0){
		m=m-i*(a[n]-a[1]);
		i++;
	}
	if(m==0){
		cout<<i;
		return 0;
	}
	else{
		cout<<i-1;
		return 0;
	}
	if(n==1||m==0){
		cout<<1;
		return 0;
	}
	return 0;
}
