#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	int l,r,best,mid;
	long long sum=0;
	for(int i=1;i<=n;i++){
		l=0,r=i,best=-1;
		while(l<=r){
			mid=(l+r)>>1;
			sum=1ll*(i-mid)*a[i]-(s[i]-s[mid]);
			if(sum<=m){
				best=i-mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,best);
	}
	cout<<ans;
	return 0;
}