#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
int h[500005],d[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin >>n>>m;
	for(int i=1;i<=n;++i){
		cin >>h[i];
	}
	sort(h+1,h+1+n);
	for(int i=2;i<=n;++i){
		d[i]=d[i-1]+(h[i]-h[i-1])*(i-1);
	}
	int gs=0;
	for(int i=1;i<=n;++i){
		if(d[i]<=m&&d[i+1]>m){
			gs=i;
			break;
		}
	}
	cout<<gs;
	return 0;
}