#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int plas=0,desk[500005];
		for(int j=i;j<=n;j++){
			for(int f=0;f<plas;f++){
				if(desk[f]==a[j]){
					plas=f;
					break;
				}
			}
			desk[plas]=a[j];
			plas++;
		}
		for(int j=0;j<plas;j++){
			ans[desk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
