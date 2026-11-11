#include <bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n,m,num,ans=-1;
long long a[N],b[N];
bool check(long long mid){
	long long sum=0;
	num=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=mid) sum+=mid-a[i],num++;
		else break;
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long l=0,r=a[n]+1;
	while(l<+r){
		long long mid=(l+r)/2;
		if(check(mid)==true) {
			l=mid+1;
			ans=max(ans,num);
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
