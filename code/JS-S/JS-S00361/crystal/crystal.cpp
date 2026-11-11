#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[500006];                
int a[500005];
int vis[1][1];
int sum;
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
	}
	}
		
	
	for(int i=0;i<n;i++){
		
		
		m-=a[n/2]-a[i];
		a[i]=a[n/2];
	
		if(m<=0)break;
		
			
	}
	
	
	
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1])sum++;
	}
	sum++;
	cout<<sum;
	return 0;
}
