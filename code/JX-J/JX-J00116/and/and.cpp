#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	if(m==2){
	long long d=a[1];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			d=max(d,a[i]&a[j]);
		}
	}
	cout<<d;
}
else {
	long long d=a[1];
	for(int i=1;i<=n;i++){
		d=max(d,a[i]);
	}
	cout<<d;
}
return 0;	
}
