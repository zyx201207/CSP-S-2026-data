#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N],n,m;
long long dp[N],f[N],ans=0;
int f1=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long h=a[2]-a[1];
	for(long long  i=2;i<=n;i++){
    	if(a[i]-a[i-1]!=h){
    		f1=1;
		}
	}
	if(f1==0){
		long long b=1;
		while(b*h<=m){
			m-=b*h; 
			b++;
		}
		cout<<b<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long k=m,k1=0;
		long long j=i;
		while(k>0&&j>=1){
			k1+=a[j]-a[j-1];
			k=k-k1;
			j--;
	    }
	    if(k==0){
	    	ans=max(ans,i-j+1);
		}else{
			ans=max(ans,i-j);
		}
	}
	cout<<ans;
	return 0;
}

