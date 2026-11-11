#include<bits/stdc++.h>
using namespace std;
void a(){
	int n,d;
	cin>>n>>d;
	int a[n],b[n-1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0) b[i-1]=a[i]-a[i-1];
	}
	int t=0;
	for(int i=0;i<=n-4;i++){
		if(d>=b[i]+b[i+1]) t++;
	}
	cout<<t<<endl;
}
int main(){
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		a();
	}
	freopen("migrate.in.txt","r",stdin);
	freopen("migrate.out.txt","w",stdout);
}
