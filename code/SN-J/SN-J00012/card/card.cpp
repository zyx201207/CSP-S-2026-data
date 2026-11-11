#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for (int i = 1;i<=n;i++){
		int b[500005] = {0};
		for (int j = i;j<=n;j++){
			b[j] = a[j];
			for (int k = i;k<j;k++){
				if (b[k]==b[j]){
					for (int t = k;t<j;t++){
						b[t]=0;
					}
					break;
				}
			}
		}
		for (int j = i;j<=n;j++){
			if (b[j]){
				ans[b[j]]++;
			}
		}
	}
	for (int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
