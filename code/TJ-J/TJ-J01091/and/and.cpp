#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long f[N];
long long maxx=-0x3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		for(int j=1;j<=m;j++){
			long long mx=-0x3f3f3f3f;
			for(int k=i+1;k<=n;k++){
				mx=max(mx,sum&a[k]);
			} 
			sum=mx;
		}	
		maxx=max(maxx,sum);
	} 
	cout<<maxx;
	return 0;
}
