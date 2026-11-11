#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long g[N];
long long t[N];
bool cmp(int a,int b){
	if(a<b) return 1;
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	sort(g+1,g+1+n,cmp);
	int ans=-0x3f3f3f3f;
	t[1]=0;
	for(int i=2;i<=n;i++){
		long long sum=t[i-1]+(g[i]-g[i-1])*(i-1);
		t[i]=sum;
		if(sum<=m) ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}