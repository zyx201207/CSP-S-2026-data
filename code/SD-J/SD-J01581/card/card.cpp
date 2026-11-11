#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],st[500005],top=0,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int q=1;q<=n;q++){
		for(int i=1;i<=m;i++){
			for(int j=i-1;j<=n;j++){
				for(int k=0;k<top;k++){
					if(st[k]==a[j]){
						top=k;
						break;
					}
				}
				st[top++]=a[j];
			}
			for(int k=0;k<top;k++)
				if(st[k]==i)
					ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
