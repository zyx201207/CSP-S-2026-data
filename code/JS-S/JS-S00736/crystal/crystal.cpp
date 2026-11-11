#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int pre[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	int pos=1;
	for(int i=1;i<=n;i++){
		while(pos<=i&&(i-pos+1)*a[i]-(pre[i]-pre[pos-1])>m){
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}