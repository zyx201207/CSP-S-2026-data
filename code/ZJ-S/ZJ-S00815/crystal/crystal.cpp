#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,res;
int a[N],pre[N];
bool check(int mid,int x){
	int num=pre[x]-pre[mid-1];
	if(a[x]*(x-mid+1)<=m+num) return true;
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		res=max(res,i-l+1);
	}
	cout<<res<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}