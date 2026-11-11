#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=0;
ll a[500005];
int flag=0;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll cnt=0,ans=0;
		int x=a[i];
		for(int j=i-1;j>=1;j--){
			if(cnt+x-a[j]>m){
				flag=1;
				break;
			}
			else cnt+=x-a[j];
		}
		if(!flag)maxn=max(maxn,i);
	}
	cout<<maxn;
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
} 
