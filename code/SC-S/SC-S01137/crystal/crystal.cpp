#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>=y;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long crystal[50005];
	for(long long i=1;i<=n;i++){
		cin>>crystal[i];
	}
	sort(crystal+1,crystal+1+n,cmp);
	long long ans=0;
	for(long long i=crystal[n];i<=crystal[1]+m;i++){
		long long sum=0,cnt=0;
		for(long long j=1;j<=n;j++){
			if(i>=crystal[j]){
				sum+=(i-crystal[j]);
				cnt++;
			}
			if(sum>m){
				ans=max(ans,cnt);
				
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
