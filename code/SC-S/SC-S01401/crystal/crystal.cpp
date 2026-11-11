#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
long long n,m,l,r,a[N],cost,ans,cnt,cha[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	l=1;r=0;
	while(l<=n&&r<=n){
		ans=max(ans,r-l+1);
		if(cost+(r-l+1)*cha[r+1]<=m){
			r++;
			cost=cost+(r-l)*cha[r];
			
		}
		else if(cost+(r-l+1)*cha[r+1]>m){
			cost-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}