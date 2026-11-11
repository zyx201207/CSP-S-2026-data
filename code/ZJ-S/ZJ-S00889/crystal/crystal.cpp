#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=1e3+10;
const int mod=1e9+7;
const int inf=1e17;
inline int mm(int X,int MOD=mod){
	return (X%MOD+MOD)%MOD;
}
int n,m;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	int ans=1;
	int las=0;
	while(l<=n){
		while(las+(a[r+1]-a[r])*(r-l+1)<=m&&r<n){
			las+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
//		cout<<l<<' '<<r<<endl;
		ans=max(ans,r-l+1);
//		cout<<a[l]<<' '<<l<<' '<<r<<' '<<las<<endl;
		las-=a[r]-a[l];
		l++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 4 2 8 9

5 8
-3 -1 2 2 7
*/
