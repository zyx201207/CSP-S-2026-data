#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,ans=0;
long long a[500050],pre[500050];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<=n; i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(long long i=1; i<=n; i++){
		long long l=1,r=i,res=-1;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m){
				r=mid-1;
				res=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}//Oct31==Dec25?
