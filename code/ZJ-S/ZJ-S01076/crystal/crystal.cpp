#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n,j=n+1;i>=1;i--){
		m+=(a[i+1]-a[i])*(i-j+1);
		while(j>1&&m>=a[i]-a[j-1]){
			j--;
			m-=a[i]-a[j];
		}ans=max(ans,(ll)(i-j+1));
	}cout<<ans;
	return 0;
}