#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,a[MAXN],t[MAXN],x[MAXN],xt[MAXN],tx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xt[a[j]]==0){
				x[++tx]=a[j];
				xt[a[j]]=tx;
			}
			else{
				int y=xt[a[j]];
				for(int k=xt[a[j]];k<=tx;k++){
					xt[x[k]]=0;
					x[k]=0;
				}
				tx=y;
				x[tx]=a[j];
				xt[a[j]]=tx;
			}
		}
		for(int j=1;j<=m;j++){
			if(xt[j]!=0) t[j]++;
		}
		for(int j=1;j<=tx;j++){
			xt[x[j]]=0;
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}