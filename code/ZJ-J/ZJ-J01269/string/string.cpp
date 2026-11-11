#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,a[200100],mi=LONG_LONG_MAX,ans;
char c[200100];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	int t=1,w=n;
	while(t<=w){
		mi=min(a[t],a[w]);
		if(c[t]==c[w]){
			if(a[t]>a[w]) w--,a[t]-=mi;
			else t++,a[w]-=mi;
		}
		else{
			ans+=mi;
			if(a[t]>a[w]) w--,a[t]-=mi;
			else t++,a[w]-=mi;
		}
	}
	cout<<ans;
	return 0;
}

