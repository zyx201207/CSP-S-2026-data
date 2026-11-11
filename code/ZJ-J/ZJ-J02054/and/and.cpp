#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+5;

int n,m;
int a[MAXN],vis[2];

int yu(int a, int b){
	int x[32],y[32];
	for(int i=0;i<=31;i++){
		x[i]=0;
		y[i]=0;
	}
	int i=31;
	while(a){
		x[i--]=a%2;
		a/=2;
	}
	i=31;
	while(b){
		y[i--]=b%2;
		b/=2;
	}
	
	int ans=0;
	int bin=1;
	for(int i=31;i>=0;i--){
		if(x[i]==1 && y[i]==1){
			ans+=bin;
		}
		bin*=2;
	}
	
	return ans;
}

bool flaga=true;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flaga=false;
	}
	
	if(m==1){
		int maxa=0;
		for(int i=1;i<=n;i++) maxa=max(maxa,a[i]);
		cout<<maxa;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=yu(ans,a[i]);
		cout<<ans;
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,yu(a[i],a[j]));
		}
		cout<<ans;
		return 0;
	}else if(flaga && yu(n,n-1)==0){
		int ans=a[n];
		for(int i=n-1;i>=n-m;i--) ans=yu(ans,a[i]);
		cout<<ans;
		return 0;
	}else{
		int ans=0;
		for(int k=1;k<=m-1;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i!=vis[0] && i!=vis[1] && j!=vis[0] && j!=vis[1]){
						if(yu(a[i],a[j])>ans){
							ans=yu(a[i],a[j]);
							vis[0]=i;
							vis[1]=j;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
