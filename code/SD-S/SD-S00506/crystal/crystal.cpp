#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N = 5e5 + 10 , inf = 0x3f3f3f3f ;
int a[N],b[N];
signed main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  b[i-1]=a[i]-a[i-1];
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	int res=0;
	for(int i=1,j=1;i<n and j<n ;){
		
		int len=j-i+1;
		if(res+b[j]*len<=m){
			ans=max(len+1,ans);
			res+=b[j]*len;
//			cout<<i<<' '<<j<<' '<<res<<endl;
			j++;
		} 
		else{
			res-=(a[j]-a[i]);
			i++;
		}
	}
	cout<<ans;

	return 0;
}
//  Oct31==Dec25?
/*
 5 5 
 1 2 4 8 9
 
 5 8
-3 -1 2 2 7

5 8 
2 4 5 6 7

*/
