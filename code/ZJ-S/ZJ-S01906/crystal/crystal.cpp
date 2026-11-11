#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500010],b[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	b[1]=0;
	long long l=1,r=1,sum=0;
	while(r<=n){
		if(sum+b[r]*(r-l)<=m){
			sum+=b[r]*(r-l);
			ans=max(ans,r-l+1);
		}
		else{
			sum-=a[r-1]-a[l];
			l++;
			r--;
		}
		r++;
	}
	cout<<ans;
	return 0;
}