#include<bits/stdc++.h>
using namespace std;   

#define ll long long
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]>m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
