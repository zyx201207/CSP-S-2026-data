#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	vector<pair<int,int>> ans[n+1];
//	ans[1].first = 1;ans[1].second = m;
int ans =1,l;
l = 1;
	for(int i=2;i<=n;i++){
		int f = a[i]-a[i-1];
		f*=(i-l);
		m-=f;
		if(m<0){
			while(true){
				if(l == i){
					break;
				}
				if(m>=0){
					break;
				}
				m+=(a[i]-a[l]);
				l++;
			}
		}
		ans = max(i-l+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
