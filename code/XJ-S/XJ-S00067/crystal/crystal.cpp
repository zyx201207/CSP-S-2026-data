#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int n,m,a[N];
int d[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++)
		d[i]=a[i+1]-a[i];
	int ans=1;
	int l=1,r=0;
	int used=0;
	int need_diff=0;
	for(int i=1;i<=n;i++){
		r++;
		used+=d[i]*(r-l+1);
		need_diff+=d[i];
		if(used>m){
		while(used>m){
			used-=need_diff;
			need_diff-=d[l];
			l++;
			}
		}	
		ans=max(ans,(r-l+2));
	}
	cout<<ans<<endl;
	return 0;
}
