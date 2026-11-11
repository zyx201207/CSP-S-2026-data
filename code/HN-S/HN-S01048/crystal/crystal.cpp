#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=n-1,sum=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[i-1]-s[mid-1]>=a[i]*(i-mid)*1LL-m){
				r=mid-1;
				sum=mid;
			}
			else l=mid+1;
		}
		if(sum!=-1) ans=max(ans,i-sum+1);
	}
	cout<<ans;
	return 0;
}
