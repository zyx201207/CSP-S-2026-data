#include<bits/stdc++.h>
using namespace std;
int c[500010],a[500010],b[500010],d[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=j;
			}else{
				for(int k=c[a[j]];k<=j-1;k++){
					d[k]=0;
				}
				c[a[j]]=j;
			}
			d[++t]=a[j];
		}
		for(int j=1;j<=t;j++){
			b[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
