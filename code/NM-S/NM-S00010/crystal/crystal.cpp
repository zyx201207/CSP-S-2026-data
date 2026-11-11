#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],c,ans,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		c=0;
		for(long long j=i-1;j>0;j--){
			c =a[i]-a[j];
			if(c<=m){
				d++;
			}
		}
		if(d!=0){
		ans = max(d,ans);
	}
	}

	cout<<ans/2;
return 0;
}
