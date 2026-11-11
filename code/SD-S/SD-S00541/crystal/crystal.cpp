#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const int N=5e5+5;
ll a[N],c[N],t[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	ll m;cin>>n>>m; 
	ll cnt=0,f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=abs(a[i]-a[i-1]);
	}
	while(m>0){
		ll minn=1e12,w=1;
		for(int i=1;i<=n;i++){
			if(c[i]<minn&&!t[i]&&!t[i+1]){
				minn=c[i];
				w=i;
			}else if(c[i]*2<minn&&!t[i]){
				minn=c[i]*2;
				w=i;
			}
		}
		m-=c[w];
		if(c[w]==0) cnt++;
		if(t[w+1]==1) m-=c[w];
		else c[w+1]+=c[w];
		t[w]=1,c[w]=0;
		if(m>=0) cnt++;
	}
	cout<<cnt;
	return 0;
}


