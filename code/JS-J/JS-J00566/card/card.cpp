#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,c[500000][1000],p,d[1000000],k=0,z;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
int a[n+1];
for(i=1;i<=n;i++){
cin>>a[i];
}
for(j=0;j<n;j++){
	k++;
for(i=j+1;i<=n;i++){
	c[a[i]][k]++;
if(c[a[i]][k]==2){
k++;
c[a[i]][k]=1;
}
}
for(z=1;z<=m;z++){
if(c[z][k]==1)
d[z]++;
}
}
for(i=1;i<=m;i++){
cout<<d[i]<<" ";
}
return 0;
}
