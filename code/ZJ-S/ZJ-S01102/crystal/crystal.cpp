#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long r=1;
	long long sum=0;
	long long ans=0;
	for(long long l=1;l<=n;l++){
		while(r<=n){
			if(l!=r&&(a[r]-a[r-1])>((m-sum)/(r-l))){
				r--;
				break;
			}
			sum=sum+(r-l)*(a[r]-a[r-1]);
			r++;
		}
		if(sum<=m){
			ans=max(ans,r-l+1);
		}else{
//			sum-=(r-l)*(a[r]-a[r-1]);
			ans=max(ans,r-l+1);
		}
		sum-=a[r]-a[l];
	}
	cout<<ans;
	return 0;
}
