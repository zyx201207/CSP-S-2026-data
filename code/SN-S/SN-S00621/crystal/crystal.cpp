#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=1; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if((a[n]-a[1])/(a[2]-a[1])+1==n){
		sum=(a[n]-a[1])*n/2;
	}
	else{
		int x=1;
		for(int i=x+1;i<=n;i++){
			if(m>0){
				if(a[x]+m>=a[i]){
					m=m-(a[i]-a[x]);
					a[x]=a[i];
					sum++;
				}
				else x++;
			}	
		}
	}
	cout<<sum;
	return 0;
} 
