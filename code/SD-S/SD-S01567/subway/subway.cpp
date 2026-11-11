#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10; 
const int M=5e2+10;
int c,n,m,d,q;
int w[N],tx[N],ty[N],a[M][M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=q;i++)
		cin>>tx[i]>>ty[i];
	
	return 0;
} 
