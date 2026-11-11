#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[500005],b[500005],c[500005];
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	bool f=0;
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			c[j]=c[j-1]+b[i]*(j-i+1);
			if(j==i&&c[j]>m){
				f=1;
				ans=j-1;
				break;
			}
			if(c[j]>m){
				ans=j-1;
				break;
			}
		}
		if(f==1) break;
	}
	cout<<ans;
	return 0;
} 