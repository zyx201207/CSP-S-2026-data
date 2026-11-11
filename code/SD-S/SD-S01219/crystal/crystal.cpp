#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+1000;
int n,m;
int a[N],sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc crystal1.ans crystal.out");return 0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	a[n+1]=1e14;
	int lst=1,ans=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=a[lst]){
			int cnt=i-lst,val=a[lst];
			ans=max(ans,cnt);
			if(lst!=1){
				int l=1,r=lst;
				while(l<r){
					int mid=((l+r)>>1);
					if((lst-mid)*val-(sum[lst-1]-sum[mid-1])<=m) r=mid;
					else l=mid+1;
				}
				ans=max(ans,cnt+lst-l);
//				if(cnt+lst-l==4237) cerr<<i<<" "<<lst<<" "<<l<<" "<<val<<" "<<sum[4237]<<":::\n";
			}
			lst=i;
			
		}
	}cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
