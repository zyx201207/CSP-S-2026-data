#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,sum,ans,maxx,k,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;++i){
		if(b[i]<=m) continue;
		else{
			cout<<i-1;
			return 0;
		}
	}
	for(int i=2;i<=n;++i){
		while(a[i]==a[i-1]){
			i++;
		}
		
	}
	ll l=1;
	for(int i=2;i<=n;++i){
		while(a[i]==a[i-1]){
			i++;
		}
		maxx=max(maxx,i-l);
		l=i;
	}
	cout<<maxx;
	return 0;
}
