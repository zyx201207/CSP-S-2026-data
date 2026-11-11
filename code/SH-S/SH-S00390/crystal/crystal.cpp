#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = (5e5+5);
int n,m,a[MAXN],pre[MAXN],l,r,mid,ans;
int getsum(int l,int r){
	return (pre[r]-pre[(l-1)]);
} 
bool check(int l,int r){
	return ((((r-l+1)*a[r])-getsum(l,r)) <= m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort((a+1),(a+n+1));
	for(int i = 1;i <= n;i++){
		pre[i] = (pre[(i-1)]+a[i]);
	}
	for(int i = 2;i <= n;i++){
		l = 1;
		r = i;
		while(l < r){
			mid = ((l+r)/2);
			if(check(mid,i)){
				r = mid;
			}
			else{
				l = (mid+1);
			}
		}
		ans = max(ans,(i-l+1));
	}
	cout<<ans<<endl;
	return 0;
} 
