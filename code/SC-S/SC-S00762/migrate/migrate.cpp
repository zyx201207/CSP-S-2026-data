#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,ans;
ll d,x[N],pre[2][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c>>t;
	x[0]=-2e18;
	while (t--){
		cin >> n>>d;ans=0;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}for (int z=1;z<n;z++){
			pre[1][z]=1;pre[0][z]=0;
			for (int i=z+1;i<=n;i++){
				pre[0][i]=N;
				for (int j=i-1;j>=z&&x[j]+d>=x[i];j--){
					if (pre[0][i]>pre[0][j]+1){
						pre[0][i]=pre[0][j]+1;
						pre[1][i]=pre[1][j];
					}else if (pre[0][i]==pre[0][j]+1){
						pre[1][i]++;
					}
				}if (pre[1][i]==2){
					ans++;
				}
			}
		}
		cout << ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}