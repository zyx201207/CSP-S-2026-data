#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6009;
const int INF=1e18;
int c,t,n;
ll d;
ll x[N],sf[N][N];
int cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cnt=1;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		/*for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sf[i][j]=INF;
			}
		}*/
		cout<<cnt<<endl;
		cnt++;
	}
	return 0;
}
