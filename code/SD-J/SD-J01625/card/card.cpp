#include <bits/stdc++.h>
using namespace std;
int a,b,c[10000005],f[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>a>>b;
for(int i=1;i<=a;i++){
	cin>>c[i];
}
for(int i=1;i<=a;i++){
	int u=0;int d[100005]={0},e[100005]={0};
	for(int j=i;j<=a;j++){u++;
		if(e[c[j]]){int h=e[c[j]];
			for(int k=h;k<=u;k++){
			e[d[k]]=0;d[k]=0;}
			u=h;e[c[j]]=u;d[u]=c[j];
		}else{
			
			e[c[j]]=u;
			d[u]=c[j];
		}
	}
	for(int j=1;j<=b;j++){
		if(e[j])f[j]++;
	}
}for(int i=1;i<=b;i++)cout<<f[i]<<" ";
return 0;
}
