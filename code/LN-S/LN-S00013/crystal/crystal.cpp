#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=1,sum=1,mx=-1;
	while(r<n){
		if((a[r+1]-a[r])*(r-l+1)<=m){
			m-=(a[r+1]-a[r])*(r-l+1);
			sum++;
			r++;
		}else{
			m+=a[r]-a[l];
			sum--;
			l++;
		}
		mx=max(sum,mx);
	}
	cout<<mx;
	return 0;
}
