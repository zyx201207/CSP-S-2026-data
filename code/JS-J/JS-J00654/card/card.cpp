#include<bits/stdc++.h>
using namespace std;
int c[400000],d[400000],e[400000],f[400000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","r",stdout);
int a,b;
cin>>a>>b;
for(int i=1;i<=a;i++)
{cin>>c[i];
}
for(int i=1;i<=a;i++){
for(int j=i;j<=a;j++){
d[j]=c[j];
e[d[j]]++;
if(e[d[j]]>1)
{for(int u=1;u<=b;u++)
e[u]=0;
e[d[j]]++;
}
}
for(int w=1;w<=b;w++){
f[w]=f[w]+e[w];
e[w]=0;
}
}
for(int w=1;w<=b;w++)
cout<<f[w];
}
