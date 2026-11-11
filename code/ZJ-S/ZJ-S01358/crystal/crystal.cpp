#include<bits/stdc++.h>

using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl "\n"

const int N=2e6+10;

int n,a[N],k,kk;

signed main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	IOS;
		
	cin>>n>>k;
	
	kk=k;
	
	int flag1=1,flag2=1;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(n==1) {
		
		cout<<1;
		
		return 0;
		
	}
	
	sort(a+1,a+n+1);
	
	int d=a[2]-a[1];
	
	for(int i=2;i<=n;i++) {
		
		if(a[i]!=i) flag1=0;
		
		if( (a[i+1]-a[i])!=d ) flag2=0;
		
	}
	
	if(flag1) {
		
		cout<<(int)(sqrt(k*2))+1;
		
		return 0;
		
	}
	
	if(flag2) {
		
		cout<<(int)(sqrt(k/d*2))+1;
		
		return 0;
		
	}
	
	int sum=1,st=1,ans=1;
	
	for(int i=1;i<=n;i++) {
		
		if( i*(a[i+1]-a[i])<=k || a[i]==a[i+1] ) {
				
			k-=(i-st+1)*(a[i+1]-a[i]);
			
			sum=max(i+1-st+1,sum);
				
			ans=max(ans,sum); 
				
		}else k=kk,st=i+1;
		
	} 
	
	cout<<ans;
	
	return 0;
	
} 
