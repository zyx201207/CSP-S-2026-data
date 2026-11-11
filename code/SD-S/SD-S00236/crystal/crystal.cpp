#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	int cnt=1;
	ll sum=0;
	ans=cnt;
	for(int l=1,r=2;r<=n;r++){
		sum+=cnt*(a[r]-a[r-1]);
		cnt++;
		while(sum>m&&l<=r){
			sum-=a[r]-a[l];
			l++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
