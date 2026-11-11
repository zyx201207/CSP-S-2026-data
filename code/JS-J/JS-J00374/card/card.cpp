#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],cnt[500005],c[500005];
ll n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1])cnt[a[i]]+=i;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
