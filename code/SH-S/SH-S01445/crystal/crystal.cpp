#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n;
ll m,a[maxn],s[maxn],ans=1,pos=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		while(pos<=n && (pos-i+1)*a[pos]-s[pos]+s[i-1]<=m){
			pos++;
		}
		pos--;
		ans=max(ans,pos-i+1);
	}
	cout<<ans;
	return 0;
} 
