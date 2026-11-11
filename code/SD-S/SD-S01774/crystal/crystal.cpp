#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn=5e5+10;

ll n,m;
ll a[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int len=0;
	if(n%2!=0) len=(n+1)/2;
	else len=n/2;
	int l=len-1,ans=1;
	while(m){
		ans++;
		m-=a[len]-a[l];
		l--;
	}
	for(int i=len+1;i<=n;i++)
		if(a[i]==a[len]) ans++;
	cout<<ans;
	return 0;
}
