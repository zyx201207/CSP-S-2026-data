/*
可以用递推的方式求出两点之间的最短路和最短路数量。
时间复杂度 O(n^2logn)
期望得分 40pts
100+44+40=184pts
比预想的 150pts 要好。
可以拿1=吗？
update:现在是 100+100+40=240pts了，1=无疑了好吧，我无敌了（半场开香槟ing）。
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int n,dst[N],ans;
long long d,a[N],num[N];

void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		dst[i]=0,num[i]=1;num[i+1]=0;
		for(int j=i-1;j>=1;j--){
			if(a[j+1]-a[j]>d) break;
			int l=j+1,r=i,res;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[j]<=d) l=mid+1,res=mid;
				else r=mid-1;
			}
			l=j+1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(dst[mid]<=dst[res]) r=mid;
				else l=mid+1;
			}
			num[j]=num[r]-num[res+1];
			dst[j]=dst[res]+1;
			if(num[j]==2) ans++;
			num[j]+=num[j+1];
		}
	}
	cout<<ans<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>T>>T;
	while(T--) solve();
	return 0;
}
