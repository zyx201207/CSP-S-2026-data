#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8;
long long a[N],c[N],f[5008][5008];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=a[j]-a[i];
		}
	}
	for(long long i=n;i>=1;i--){
		long long k=m,aa=1;
		for(long long j=i-1;j>=1;j--){
			long long l=a[i]-a[j];
			if(l<=k){
				k-=l;
				++aa;
			}
		}
		ans=max(ans,aa);
	}
	cout<<ans;
	return 0;
}
