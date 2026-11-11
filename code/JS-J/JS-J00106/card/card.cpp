#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005],ans;
int f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(long long i=1;i<n;i++){
		if(a[i]>a[i+1]){
			f=0;
		}
	}
	if(f){
		for(long long i=1;i<=m;i++){
			ans=0;
			for(long long j=1;j<=i;j++){
				ans+=c[j];
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
