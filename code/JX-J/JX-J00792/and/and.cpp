#include<bits/stdc++.h>
using namespace std;
int r(int a,int b){
int c[10000],d[10000],e[10000],sum=1,sum2=1,sum3=1,x=0;
while(a){
    c[sum]=a%2;
    a/=2;
    sum++;
}
while(b){
    d[sum2]=b%2;
    b/=2;
    sum2++;
}
for(int i=1;i<min(sum,sum2);i++)
if(c[i]==d[i])
{e[sum3]=1;
sum3++;}
else
{e[sum3]=0;
sum3++;}
for(int i=1;i<sum3;i++)
   x+=e[i]*pow(2,i-1);
return x;
}
bool cmp(int a,int b){
return a>=b;}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,a[10000],b[10000],num=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
if(m==2){
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
{b[i]=r(a[i],a[j]);
num++;}
sort(b+1,b+num+1,cmp);
cout<<b[1];}
if(m==1){
    for(int i=1;i<=n;i++)
        {b[i]=r(a[i],0);
        num++;}
    sort(b+1,b+num+1,cmp);
    cout<<b[1];
}
return 0;}
