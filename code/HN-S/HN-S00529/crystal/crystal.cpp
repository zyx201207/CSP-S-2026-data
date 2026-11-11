#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000050],sum[50000050],cnt=1,maxx=-100050,mm,r=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	sum[1]=0;
	for(long long i=2;i<=n;i++){
		r++;
		int c=a[i]-a[i-1];
		sum[i]=sum[i-1]+r*c;
	}
	for(long long i=1;i<=n;i++){
		if(sum[i]<=m){
			maxx=max(maxx,i);
		}else{
			break;
		}
	}
	cout <<maxx;
	return 0;
}
