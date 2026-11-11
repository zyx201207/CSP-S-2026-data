#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
ll m,a[500005],s[500005];
bool check(int t,int loc){
	ll num=t-loc+1,lst=0;
	lst=num*a[t]-(s[t]-s[loc-1]);
	if(lst<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,sum=1,mid=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(i,mid)){
				sum=max(sum,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}