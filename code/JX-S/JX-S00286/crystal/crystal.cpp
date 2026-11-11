#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005]={0},b[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]+=b[i-1]+a[i];
	}
	long long l=0,r=n;
	while(l<r){
		long long mid=l+(r-l)/2;
		bool pp=0;
		for(long long i=mid;i<=n;i++){
			long long p=a[i]*mid-(b[i]-b[i-mid]);
			if(p<=m) {
				pp=1;
				break;
			}
		}
		if(pp) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
