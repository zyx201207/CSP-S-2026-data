#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int maxn=5e5+10;
int a[maxn];
ll ans=-1e9;
ll cnt,sum=0;
ll min_i=-1e17;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		sum=0;
		for(int j=1;j<=n;j++){
			if(sum+abs(a[i]-a[j])<=m){
				cnt++;
				sum+=abs(a[i]-a[j]);
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/

