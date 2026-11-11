#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500005],maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long ans=1,b=m;
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){
				if(a[i]-a[j]<=b){
					b-=a[i]-a[j];
					ans++;
				}
			}else if(a[i]==a[j]){
				ans++;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 
