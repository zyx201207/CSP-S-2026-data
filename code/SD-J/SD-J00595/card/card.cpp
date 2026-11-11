#include <iostream>
using namespace std;
int n,m,a[500002],bd[500002],last[300002],ans[300002];
bool vis[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	bd[n]=n+1;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;){
			if (!last[a[j]]){
				last[a[j]]=j;
				bd[j]=j+1;
			}
			else{
				bd[last[a[j]]]=j;
				bd[j]=j+1;
				last[a[j]]=j;
			}
			j=bd[j];
		}
		for (int j=i;j<=n;){
			if (!vis[a[j]]){
				vis[a[j]]=1;
				ans[a[j]]++;
			}
			j=bd[j];
		}
		for (int j=i;j<=n;){
			vis[a[j]]=0;
			j=bd[j];
		}
	}
	for (int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
