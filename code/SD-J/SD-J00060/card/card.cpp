#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],h[500010],d[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=i;j<=n;j++){
			k++;
			for(int x=1;x<=k;x++){
				if(h[j]==d[x]){
					for(int y=x+1;y<=k;y++){
						d[y]=0;
					}
					k-=k-x;
					break;
				}
			}
			d[k]=h[j];
		}
		for(int j=1;j<=k;j++){
			ans[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
