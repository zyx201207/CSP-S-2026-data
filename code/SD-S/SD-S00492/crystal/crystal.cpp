#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
ll n,m,a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=-0x3f3f3f3f;
	memset(a,0,sizeof a);
	memset(s,0,sizeof s);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}int zuo=1; int you=1;
	while(you<=n){
		ll tmp=a[you]*(you-zuo+1)-s[you]+s[zuo-1];
		if(tmp>m) zuo++;
		else ans=max(ans,you-zuo+1),you++;
	}
	cout<<ans;
	return 0;
}
