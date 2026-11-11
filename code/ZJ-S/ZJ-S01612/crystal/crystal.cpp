#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll m,a[N],pre[N];
bool check(int p){
	if(p==0)return true;
	if(p>n)return true;
	for(int i=p;i<=n;++i)
		if(p*a[i]-pre[i]+pre[i-p]<=m)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		pre[i]=pre[i-1]+a[i];
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid==0){
			cout<<'0';
			return 0;
		}
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
}
