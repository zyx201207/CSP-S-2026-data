#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],b[N],c[N],k[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],c[a[i]]=i;
	for(int i=1;i<=n;++i){
		++k[i];
		b[a[i]]+=k[i],k[c[a[i]]+1]+=k[i];
	}
	for(int i=1;i<=m;++i) cout<<b[i]<<' ';
	return 0;
}
