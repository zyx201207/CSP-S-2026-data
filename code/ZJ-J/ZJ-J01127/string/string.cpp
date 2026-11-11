#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],ans;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>ch[i];
	ll l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r])ans+=min(a[l],a[r]);
		if(a[l]==a[r]){
			a[l]=a[r]=0;
			l++;
			r--;
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else{
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
