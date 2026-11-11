#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
using namespace std;
mt19937_64 rd(time(0));
const int N=5e5+5;
int n,ans,a[N],s[N],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])>m)l=mid+1;
			else r=mid-1,ans=max(ans,i-mid+1);
		}
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
