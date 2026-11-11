#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
bool check(long long x,long long y){
	if(a[x]*(x-y+1)-(s[x]-s[y-1])<=m){
		return 1;
	}
	else{
		return 0;
	}
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i-1,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(i,mid)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
} 