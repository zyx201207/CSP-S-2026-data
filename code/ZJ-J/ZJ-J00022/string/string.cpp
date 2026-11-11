#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int n,i,t,w,x,ans,a[N];char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>ch[i];
	t=1,w=n;
	while(t<w){
		if(ch[t]!=ch[w]){
			x=min(a[t],a[w]);
			ans+=x;a[t]-=x;a[w]-=x;
			if(a[t]==0)t++;
			if(a[w]==0)w--;
		}
		else{
			x=min(a[t],a[w]);
			a[t]-=x;a[w]-=x;
			if(a[t]==0)t++;
			if(a[w]==0)w--;
		}
	}
	cout<<ans;
}
//by wild cat