#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N],ans,l,r,mid,t,sum,f;
bool check(int x,int y){
	t=pre[y-1]-pre[x-1];
	sum=(y-mid)*a[y];
	if(sum-t<=m) return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	ans=1;
	for(int i=1;i<=n;i++){
		if(i==1) continue;
		l=1,r=i;
		f=i;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid,i)){
				f=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-f+1);
	}
	cout<<ans<<'\n';
	return 0;
} 