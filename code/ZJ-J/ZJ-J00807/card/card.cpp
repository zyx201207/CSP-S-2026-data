#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],g_i[M],ans[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g_i[a[i]]=i;
	}
	for(int aaaa=1;aaaa<=n;aaaa++){
		for(int j=aaaa;j<=n;j++){
			if(j!=g_i[a[j]]){
				j=g_i[a[j]];
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

