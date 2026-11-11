#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second

using namespace std;

const int N=5e5+10;
const int INF=1e16;

int n, m, a[N], d[N], s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	int max_a=-INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a, abs(a[i]));
	}
	if(n<=5000&&max_a<=1e5){
		sort(a+1, a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			int tot=0, cnt=0;
			for(int j=i-1;j>=1;j--){
				if(tot+a[i]-a[j]>m)break;
				tot+=a[i]-a[j];
				cnt++;
			}
			ans=max(ans, cnt+1);
		}
		cout<<ans<<'\n';
		return 0;
	}
	else {
		sort(a+1, a+n+1);
		int ans=0;
		for(int i=2;i<=n;i++){
			d[i]=(a[i]-a[i-1])*(i-1);
			s[i]=s[i-1]+d[i];
		}
//		for(int i=1;i<=n;i++)cout<<d[i]<<" ";
//		cout<<'\n';
//		for(int i=1;i<=n;i++)cout<<s[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			int l=1, r=i, res=-1;
			while(l<=r){
				int mid=(l+r)>>1LL;
//				cout<<"check i = "<<i<<" mid = "<<mid<<" chk = "<<s[i]-s[mid]-(mid-1)*(a[i]-a[mid])<<'\n';
				if(s[i]-s[mid]-(mid-1)*(a[i]-a[mid])<=m){
					res=i-mid+1;
					r=mid-1;
//					cout<<"upd res = "<<res<<"\n";
				}else l=mid+1;
			}
//			cout<<i<<' '<<res<<'\n'<<'\n';
			ans=max(ans, res);
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}
/*
打表过样例
骗分拿省一
NOIP 2026 RP++！

NOIP打完就AFO了qwq 
*/
