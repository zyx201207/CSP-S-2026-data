#include<bits/stdc++.h>
using namespace std;
int a[500005],x[300005],ne[500005],nw[300005],res[300005];
vector<int> v;
bool vis[300005],f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,cnt;
	cin>>n>>m;
	cnt = n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i] = 1;
	}
	for(int i=n;i>=1;i--){
		if(nw[a[i]]){
			ne[i] = nw[a[i]];
		}
		nw[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		if(ne[i]){
			x[ne[i]]+=x[i];
		}else{
			res[a[i]] = x[i];
			x[i+1]+=x[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
