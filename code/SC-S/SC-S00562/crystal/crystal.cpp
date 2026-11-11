#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[20000],x,sum=0,ans,b=0;
	cin>>n>>m;
		x=(n+1)/2;
	for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			if(a[i]==a[x]){
				b=b+1;
			}
		
	for(int j=1;j<x;j++) sum=sum+a[j];
		ans=(sum+m)/a[x]+b;

		cout<<ans;
		return 0;
	}