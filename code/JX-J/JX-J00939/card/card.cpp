#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int c[1000005],d[1000005];
int main(){
    freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++)c[j]=0;

for(int j=i;j<=n;j++){
b[j]=a[j];
if(c[a[j]]!=0){
int f=j-1,g=c[a[j]];
while(g<=f){
if(c[a[f]]==f){c[a[f]]=0;}

b[f]=0;f--;}
c[a[j]]=j;
}
else c[a[j]]=j;
}
for(int j=i;j<=n;j++)d[b[j]]++;
}
for(int i=1;i<=m;i++)cout<<d[i]<<" ";
return 0;
}
