#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(long long x,long long y){
	return (x<y);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long l=1,r=n;
	while(l<=r){
		cnt=0;
		long long _ans=0;
		long long mid=(l+r)/2;
		for(int i=mid-1;i>=1;i--){
			if(cnt<m) cnt+=(a[mid]-a[i]);
			else break;
			_ans++;
		}
		if(_ans>ans){
			ans=_ans;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 