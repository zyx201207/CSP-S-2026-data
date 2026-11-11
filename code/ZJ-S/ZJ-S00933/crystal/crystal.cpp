#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],ans=1;
ll q[500010],l,r,sum,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1,r=0;
	sum=m;
	for(ll i=1;i<=n;i++){
		if(sum>=(a[i]-a[q[r]])*cnt){
			sum-=(a[i]-a[q[r]])*cnt;
			cnt++;
			q[++r]=i;
		}else{
			ans=max(ans,cnt);
			while(l<=r&&sum<(a[i]-a[q[r]])*cnt){
				sum+=(a[q[r]]-a[l]);
				l++;
				cnt--;
			}
			i--;
		}
	}
	cout<<ans;
}