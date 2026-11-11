#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long c[500005];
long long p[500005];
long long ans[300005];
long long k[300005];
long long lo=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=1;	
	}
	for(int i=n;i>=1;i--){
		if(k[a[i]]){
			c[i]--;
			c[k[a[i]]]++;
		}
		k[a[i]]=i;
	}
	for(int i=1;i<=n;i++) p[i]=p[i-1]+c[i];
	for(int i=1;i<=n;i++) ans[a[i]]+=p[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}