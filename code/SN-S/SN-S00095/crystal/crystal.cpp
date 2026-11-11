#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005];
long long dp[500005];
long long maxx=-2147483647;
long long k,f,cnt;
bool flag=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	a[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if((i!=1)&&(i!=2)&&(d[i]!=d[i-1])) flag=0;
	}
	f=m;
	for(int i=n;i>=1;i--){
		if(i==1){
			cout<<max(maxx,k);
			return 0;
		}
		if(d[i]==0) continue;
		long long r=d[i]*(k-i+1);
		if(m<abs(r)){
			if(flag==1){
				cout<<n-i+1;
				return 0;
			}
			maxx=max(maxx,k-i+1);
			cnt++;
			i=n-cnt;
			m=f;
			k=i-1;
			continue;
		}
		if(d[i]!=0){
			m+=r;
		}
	}
	return 0;
} 
