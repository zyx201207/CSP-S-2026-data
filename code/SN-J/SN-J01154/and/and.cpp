#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,b[200005],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=29;i>=0;i--){
		if(cnt==m)break;
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				b[++cnt]=a[j];
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			n=cnt;
			for(long long i=1;i<=n;i++){
				a[i]=b[i];
				b[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
