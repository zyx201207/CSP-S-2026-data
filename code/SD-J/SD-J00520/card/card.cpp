#include<bits/stdc++.h>
using namespace std;
int a[1000010],p[20],ans[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(p,0,sizeof p);
		int pos=0;
		for(int i=k;i<=n;i++){
			for(int j=1;j<=pos;j++){
				if(p[j]==a[i]){
					for(int w=j;w<=pos;w++){
						p[w]=0;
					}
					pos=j-1;
				}
			}
			p[++pos]=a[i];
		}
		for(int i=1;i<=pos;i++){
			ans[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/ 
