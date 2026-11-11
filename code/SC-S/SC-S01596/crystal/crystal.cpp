//来自【迷惑行为大赏】的【仅售$5.99】的【小海绵】们，你们能否使我成为一个【大人物】？！
//如果你照做，我会以我最喜欢的年份为价格卖给你我的【纪念戒指】！！！
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
//			if(i==3){
//				cout<<mid<<':'<<a[i]*(i-mid)<<' '<<sum[i-1]-sum[mid-1]<<'\n';
//			}
			a[i]*(i-mid)-sum[i-1]+sum[mid-1]<=m?r=mid:l=mid+1;
		}
//		cout<<i<<':'<<i-l+1<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}