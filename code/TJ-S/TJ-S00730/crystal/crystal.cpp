#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m,a[500005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1;
	long long s=m;
	for(long long r=1;r<=n;r++){
		s-=(r-l)*(a[r]-a[r-1]);
		while(s<0&&l<r){
			s+=a[r]-a[l];
			l++;
		}
		ans=max(ans,(long long )r-l+1);
	}
	cout<<ans;
	
	
	return 0;
} 
