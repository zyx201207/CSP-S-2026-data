#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,a[N],pre[N];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[1]-a[i];
	int ans=upper_bound(pre+1,pre+n+1,m)-pre-1,sum=0,lzy=0;
	for(int i=2;i<=n;i++){
		sum+=a[i-1]-a[i];
		lzy+=a[i-1]-a[i];
		int l=i,r=n,idx=i;
		while(l<=r){
			int mid=l+r>>1ll;
			if(pre[mid]-sum-lzy*(mid-i)<=m){
				idx=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,idx-i+1);
		sum+=lzy;
	}
	cout<<ans<<endl;
	return 0;
}
