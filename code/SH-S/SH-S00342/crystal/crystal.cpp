#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+10;
int n;
ll a[N];
ll m;
ll s[N];

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(s[mid]<=s[i]+m-a[i]*(i-mid)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
//		cout<<i<<" "<<l<<'\n';
	}
	cout<<ans;
	return 0;
}
