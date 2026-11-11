#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans;
bool c(int x){
	long long sum=m;
	for(long long i=x;i>=1&&sum>=0;i--) sum-=(a[x]-a[i]);
	if(sum>=0) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(r+l+1)/2;
		if(c(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 
