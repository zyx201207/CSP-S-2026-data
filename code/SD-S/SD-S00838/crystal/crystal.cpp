#include<bits/stdc++.h>
using namespace std;
const int d=5e5;
long long n,m,a[d+5],maxx=0;
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
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2,sum=0,cnt=0;
		for(int i=mid;i>=1;i--){
			if(sum+(a[mid]-a[i])<=m){
				cnt++,sum+=(a[mid]-a[i]);
			}
		}
		if(cnt>=maxx){
			maxx=cnt;
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<maxx;
	return 0;
}
