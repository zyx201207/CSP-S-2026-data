#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],sum[500005],sum1[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans1=a[2]-a[1],f=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ans1){
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<m/ans1+1;
		return 0;
	}
	sort(a+1,a+n+1);
	sum[1]=0;
	sum1[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=(i-1)*a[i]-sum1[i-1];
		sum1[i]=a[i]+sum1[i-1];
	}
	int l=1,r=1;
	int ans=0;
	while(l<n&&r<n){
		if(sum[r]-sum[l]-((a[r]-a[l])*(l-1))<m){
			r++;
		}else if(sum[r]-sum[l]-((a[r]-a[l])*(l-1))>m){
			l++;
		}else if(sum[r]-sum[l]-((a[r]-a[l])*(l-1))==m){
			ans=max(ans,r-l+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
}

