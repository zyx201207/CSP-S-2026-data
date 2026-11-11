#include<bits/stdc++.h>
using namespace std;
int shu[500010];
int ans[500010];
int chu[500010];
int yong[500010];
int cun[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>shu[i];
	}
	int game=1;
	while(game<=n) {
		for(int i=game; i<=n; i++) {
			if(yong[shu[i]]==0) {
				yong[shu[i]]=1;
				cun[shu[i]]=i;
			} else {
				for(int j=cun[shu[i]]; j<=i; j++) {
					yong[shu[j]]=0;
				}
				yong[shu[i]]=1;
			}
		}
		for(int i=game; i<=n; i++) {
			if(yong[shu[i]]==1) {
				ans[shu[i]]++;
				yong[shu[i]]=0;
			}
		}
		game++;
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<< " ";
	}
	return 0;
}