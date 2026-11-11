#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],qz[N];
bool check(int now)
{
	int vau=a[now];
	int sum=(qz[now]+m)/now;
	if(sum>=vau) return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	int cnt=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	l--;
	int p=a[l];
	//cout<<l<<"\n";
	int ans=l;
	for(int i=l+1; ;i++)
	{
		if(a[i]==p) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
