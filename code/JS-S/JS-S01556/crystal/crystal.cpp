#include<bits/stdc++.h>
using namespace std;
long long a[1011111];
long long s[1010111];
long long d=INT_MAX;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=1;
	long long n,m,ans,ans2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
	}
	if(f==1){
		long long g=n*(n-1)/2,r=n;
		while(1){
			if(g<=m){
				cout<<r;
				exit(0);
			}
			g-=(r-1);
			r-=1;
		}
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1]+(a[i]-a[i-1])*(i-1);
	//	cout<<s[i].x<<' ';
	}
	//long long d;		
	for(int i=1;i<=n;i++){
		if(s[i]<=m&&(m-s[i])<=d){
			d=m-s[i];
			ans=i;
		}
	}
	
	cout<<ans;		
	return 0;
}	
