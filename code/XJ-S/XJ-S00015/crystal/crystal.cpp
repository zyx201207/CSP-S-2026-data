#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
constexpr int N=5e5+5;
int a[N],pre[N],ans;
bool check(int le,int cur){
	if(a[cur]*(cur-le)-(pre[cur-1]-pre[le-1])>m) return false;
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int lo=1,high=i-1;
		while(lo<=high){
			int le=(lo+high)>>1;
			if(check(le,i)) high=le-1;
			else lo=le+1;
		}
		ans=max(ans,i-lo+1);
	}
	cout<<ans;
} 
