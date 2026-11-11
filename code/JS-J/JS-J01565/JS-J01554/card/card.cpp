#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[300005];
bool f[500005],ff[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0) b[a[j]]=j;
			else{
				for(int u=b[a[j]];u<=i-1;u++){
					f[u]=1;
					b[a[u]]=0;
				}
				b[a[j]]=1;
			}
			ff[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[j]==0&&ff[a[j]]==0){
				ans[a[j]]++;
				ff[a[j]]=1;
			}
			f[j]=0;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<' ';
	return 0;
}
