#include <bits/stdc++.h>
using namespace std;
int a[500010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int i,j,t,c[500010]={0},ji1=0,p1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1){
			ji1=1;
		}
	}
	if(m==2){
		for(i=1;i<=n;i++){
			if(a[i]!=a[n]){
				c[a[i]]++;
			}
		}
		c[a[n]]=n;
		cout<<c[1]<<" "<<c[2];
		return 0;
	}
	if(ji1==0){
		for(i=1;i<=n;i++){
			c[a[i]]=i;
		}
		for(i=1;i<m;i++){
			cout<<c[i]<<" ";
		}
		cout<<c[m];
		return 0;
	}
	return 0;
}
