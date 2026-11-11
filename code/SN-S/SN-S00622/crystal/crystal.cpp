#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
ll sum,fir=1,ans=1,cntnow=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(sum+(a[i]-a[i-1])*cntnow<=m){
			sum=sum+(a[i]-a[i-1])*cntnow;
			cntnow++;
		}
		else if(a[i]-a[i-1]>m){
			ans=max(ans,cntnow);
			cntnow=1;
			fir=i;
			sum=0;
		}
		else{
			ans=max(ans,cntnow);
			while(sum+(a[i]-a[i-1])*cntnow>m){
				sum-=a[i-1]-a[fir];
				fir++;
				cntnow--;
			}
			sum=sum+(a[i]-a[i-1])*cntnow;
			cntnow++;
		}
	}
	cout<<ans;
	return 0;
}
