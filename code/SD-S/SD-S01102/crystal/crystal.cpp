#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5,mod=998244353;
int a[N],n,m;
int sum[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	system("fc crystal.out crystal1.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mina=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		mina=min(mina,a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		a[i]-=mina;
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,tans,mid;
		while(l<=r){
			mid=(l+r)/2;
			if((a[i]*(i-mid+1))-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				tans=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-tans+1);
	}
	cout<<ans;
	return 0;
}

