#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N];int n,m;
long long f(int k){
	long long t,mn=INT_MAX;
	for(int i=0;i+k<=n;i++){
		t=1ll*a[i+k-1]*k-sum[i+k]+sum[i];
		mn=mn>t?t:mn;
	}
	//cout<<k<<" "<<mn<<"kk\n";
	return mn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum[0]=0;
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+a[i];
	}
	int ans=(n+1)/2,l=0,r=n;
	while(l!=r){
		if(f(ans)<=m){
			l=ans;
			//cout<<ans<<"L\n";
		}else{
			r=ans-1;
			//cout<<ans<<"R\n";
		}ans=(l+r+1)/2;
	}
	cout<<l;
} /*
5 5
1 2 4 8 9
*/