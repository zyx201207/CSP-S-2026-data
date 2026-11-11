#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
int n,m,a[N],maxx=-1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==n){
		maxx=(a[1]&a[2]);
		for(int i=2;i<=n;i++){
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	return 0;
}
