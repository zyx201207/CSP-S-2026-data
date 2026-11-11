#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int qzh[MAXN];
int n,m;
int a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1];
	qzh[1]=a[1];
	for (int i=2;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	int l=1,r;
	int ans=0;
	for (r=1;r<=n;r++){
		while (l<=r){
			__int128 cost=(__int128)a[r]*(__int128)(r-l+1)-(__int128)(qzh[r]-qzh[l-1]);
			if (cost<=m){
				break;
			}
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
