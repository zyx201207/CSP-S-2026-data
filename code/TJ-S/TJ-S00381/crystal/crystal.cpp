#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],c[500005],d[500005],x=1,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
		d[i]=d[i-1]+i*b[i];
	}
	for(int i=1;i<=n;i){
		int tmp=d[i],j;
		for(j=1;j<=n-i+1;j++){
			if(tmp<=m){
				ans=i;
				i++;
				break;
			}
			tmp+=i*b[i+j]-c[i+j-1]+c[j-1];
		}
		if(j==n-i+2){
			break;
		}
	}
	cout<<ans+1;
	return 0;
}
