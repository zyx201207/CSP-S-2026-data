#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,k,len,b[500005],c[500005],r;
bool bl=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			bl=false;
			break;
		}
	}
	if(bl&&n>=2){
		r=c[2];
		
		for(int i=1;i<n;i++){
			ans+=r*i;
			if(ans>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	
	}
	if(a[1]<=0){
		for(int i=1;i<=n;i++){
		a[i]-=a[1];
		a[i]++;
	}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		
	}
	ans=1;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[j]-b[i-1]+m>=a[j]*(j-i+1)) len=j-i+1;
			if(ans==n){
				cout<<ans;
				return 0;
			}
			
		}
		if(len>ans) ans=len;
	}
	cout<<ans;
	return 0;
} 
