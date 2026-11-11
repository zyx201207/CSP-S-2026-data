#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j = i;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]==2){
				int jj = j;
				while(a[jj]!=a[j]||jj==j){
					jj--;
					c[a[jj]]--;
				}
			}
		}
		for(int j = 1;j<=m;j++){
			if(c[j]==1)b[j]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;	
}