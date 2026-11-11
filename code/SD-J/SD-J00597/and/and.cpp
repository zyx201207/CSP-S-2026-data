#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[200100];
int maxn=-0x3f3f3f3f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m<=1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
                if(i!=j){
                	int t=(a[i]&a[j]);
					maxn=max(maxn,t);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m=n-1){
	   maxn=0;
	   int asdc;
	   for(int i=1;i<=n;i++){
	   	    if(i!=1){
	   	   	   asdc=a[1];
			}
			else
			   asdc=a[2];
			for(int j=1;j<=n;j++){
			   	if(i!=j){
			   	    asdc=asdc&a[j];
				} 
			}
			maxn=max(maxn,asdc);
	   }
	   cout<<maxn;
	   return 0;
	}
	cout<<-1;
	return 0;
} 

