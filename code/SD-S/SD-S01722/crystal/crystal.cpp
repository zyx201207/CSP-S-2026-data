#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	int ans=1;
	int M=0;
	for(int i=2;i<=n;i++){
		M+=(i-l)*(a[i]-a[i-1]);
		if(M>m){
			int j;
			for(j=l;j<i,M>m;j++){
				M-=(a[i]-a[j]);
			}
			l=j;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
