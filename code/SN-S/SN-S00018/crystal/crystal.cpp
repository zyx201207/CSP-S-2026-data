#include <bits/stdc++.h>
using namespace std;

long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i<n;++i) cin >> a[i];
	sort(a,a+n);
	int l=0,r=0,ans=0;
	long long cost=0;
	while(r<n){
		if(l>r) ++r;
		else{
			if(cost<=m){
				ans=max(ans,r-l+1); 
				cost+=(long long)(r-l+1)*(a[r+1]-a[r]);
				++r;	
			}else{
				cost-=(a[r]-a[l]);
				++l; 
			}
		}
	}
	cout << ans;
	return 0;
} 
