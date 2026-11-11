#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,a[N],minn=1e13,maxx=-1e13,ans;
bool f=1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
			f=0;
			break;
		}
	if(f==1){
		int sum=0,z=a[2]-a[1];
		for(int i=1;i<=n;i++){
			sum+=z*(i-1);
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(n*max(abs(maxx),abs(minn))<1e8){
		for(int x=minn;x<=maxx;x++){
			int sum=0,pos=upper_bound(a+1,a+1+n,x)-a-1,cnt=0;
			for(int i=pos;i>=1;i--){
				sum+=x-a[i];
				if(sum>m)break;
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n;j++){
		int sum=0,cnt=0;
		for(int i=j;i>=1;i--){
			sum+=a[j]-a[i];
			if(sum>m)break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
