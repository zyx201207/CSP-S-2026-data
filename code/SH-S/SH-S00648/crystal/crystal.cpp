#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool check(int cnt){
	long long sum=0,j=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*min(i-1,cnt);
		if(i==cnt&&sum<=m) return true;
		if(i>cnt){
			j++;
			sum-=a[i]-a[j];
			if(sum<=m) return true;
		}
	}
	return false;
}
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
	sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}
