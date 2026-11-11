#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,mid,g,sum;
bool check(int x){
	g=a[x];
	sum=0;
	for(int i=1;i<=x;i++)
		sum+=g-a[i];
	if(sum<=m)
		return true;
	for(int i=x+1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(x+1);
		sum-=(a[i]-a[i-x]);
		if(sum<=m)
			return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	l=0,r=n;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	if(check(mid+1))cout<<mid+1;
	else if(check(mid))cout<<mid;
	else cout<<mid-1;
	return 0;
} 
