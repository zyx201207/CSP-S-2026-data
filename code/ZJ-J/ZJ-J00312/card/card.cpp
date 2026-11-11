#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,a[N],lie[N],f[N],cnt[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lie[a[i]]=i;
	}
	for(int i=n;i>=1;i--)f[i]=lie[a[i]];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			j=f[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
