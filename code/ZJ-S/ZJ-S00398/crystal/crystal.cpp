#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long ans=0;
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=1,sum=0;
	while(r<=n){
		long long len=r-l+1;
		if(sum<=m)ans=max(ans,len);
		if(sum<=m){	
			long long num=a[r+1]-a[r];
			sum+=len*num;r++;
		}else{
			long long num=a[r]-a[l];
			sum-=num;l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

