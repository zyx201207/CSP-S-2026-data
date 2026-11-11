#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int n,m,sb,cnt,maxn=-1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sb=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
		if((a[i]-a[j]>=0)&&(a[i]-a[j]<=sb)){
			sb-=a[i]-a[j];
			cnt++;
		}
	}
	maxn=max(cnt,maxn);
	}
	cout<<maxn+1;
	return 0;
}
