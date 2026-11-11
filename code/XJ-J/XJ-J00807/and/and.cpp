#include<bits/stdc++.h>
using namespace std;
int a[100001],b[1000001],c,d,e,f,g,h,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	c=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		c=(c&a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<c;
		return 0;	
	}
	c=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c<(a[i]&a[j])){
					c=(a[i]&a[j]);
				}
			}
		}
		cout<<c;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1){
				c=a[2];
			}else{
				c=a[1];
			}
			for(int j=2;j<=n;j++){
				if(j==i){
					continue;
				}
				c=(c&a[i]);
			}
			d=max(d,c);
		}
		cout<<d;
		return 0;
	}
	if(n<=20){
		
	}
	return 0;
}