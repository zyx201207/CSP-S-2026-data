#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
long long tot[500005];
bool cmp(long long x,long long y){
	return x<y;
}
long long res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    sum[0]=0;
	for(long long i=1;i<=n;++i){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	tot[1]=1;
	sum[1]=0;
	for(long long i=2;i<=n;++i){
	    long long maxtot=tot[i-1]+1;
		sum[i]=sum[i-1]+tot[i-1]*(a[i]-a[i-1]);
		if(sum[i]>m){
			for(long long j=i-tot[i-1];j<i;++j){
				sum[i]-=(a[i]-a[j]);
				maxtot--;
				if(sum[i]<=m)break;
			}
		}
		tot[i]=maxtot;
	}
	for(long long i=1;i<=n;++i){
		res=max(res,tot[i]);
	}
	cout<<res<<endl;
	return 0;
} 