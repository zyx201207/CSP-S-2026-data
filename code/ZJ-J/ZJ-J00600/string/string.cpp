#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const int maxn=2e5+5;
ll a[maxn];
char c[maxn];
int main(){
	FASTIO;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll ans=0,f=a[1],e=a[n],x=1,y=n;
	while(x<y){
		ll temp=min(f,e);
		if(c[x]!=c[y])ans+=temp;
		f-=temp;
		e-=temp;
		if(f==0)f=a[++x];
		if(e==0)e=a[--y];
	}
	cout<<ans;
	return 0;
}
