#include<bits/stdc++.h>
#define int long long
#define mid ((nl+nr)>>1)
#define f1 first
#define s2 second
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m,a[500005],s[500005],ans;
bool check(int x,int l){
	int y=x+l;
	if(y>n) return 0;
	if((l+1)*a[y]-(s[y]-s[x-1])<=m) return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=(1<<20);j>=1;j>>=1){
			if(check(i,s+j)) s+=j;
		}
		ans=max(ans,s+1);
	}
	cout<<ans;
	return 0;
}
