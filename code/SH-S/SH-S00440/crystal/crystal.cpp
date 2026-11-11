#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+7;
long long a[MAXN],sum[MAXN];
long long ans=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<i;j++){
			   long long x=(i-j)*(sum[i]-sum[i-1]);
		       if(x-sum[i-1]+sum[j-1]<=m){
			       ans=max(ans,i-j+1);
		        }	
			}
		}
	}
	else{
		for(long long i=1;i<=n;i++){
		    long long x=(i-1)*(sum[i]-sum[i-1]);
		    if(x-sum[i-1]<=m){
			    ans=max(ans,i);
		   }
	    }
	}
	cout << ans << endl;
	return 0;
}
