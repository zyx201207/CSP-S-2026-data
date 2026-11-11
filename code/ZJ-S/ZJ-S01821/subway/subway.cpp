#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int M=2e4+1,N=501;
int c,n,m,d,q,l,r,f=0;
int w[M],k[N],a[N][M],t[N][M];
int ck[N][N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i]; 
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>l>>r;
		ll ans=w[l]+w[r];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==l) ans+=t[i][j];
				if(a[i][j]==r) {
					ans+=t[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/