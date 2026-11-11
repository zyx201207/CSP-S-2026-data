#include<bits/stdc++.h>
using namespace std;
int n,m,tot,a[500010],d[500010],ans[500010];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=1;j<=n;j++) d[j]=0;
		for(int j=i;j<=n;j++){
			f=0;
			for(int k=1;k<=tot;k++){
				if(d[k]==a[j]){
					f=1;
					break;
				}
			}
			if(f){
				for(int k=1;k<=tot;k++) d[k]=0;
				tot=0;
				d[++tot]=a[j];
			}
			else d[++tot]=a[j];
		}
		for(int j=1;j<=tot;j++) ans[d[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
