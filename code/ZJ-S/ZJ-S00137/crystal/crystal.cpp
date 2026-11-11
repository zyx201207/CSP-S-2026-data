#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],sum,pos=1,vis[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;sum=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ll dla=a[i]-a[i-1];
		while(dla*(i-pos)>sum){
			sum+=a[i-1]-a[pos];
			pos++;
		}
		sum-=dla*(i-pos);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}