#include<bits/stdc++.h>
using namespace std;
char d[1000000005];
int main(){
freopen("string.in","r",stdin);
freopen("string.in","r",stdin);
int a,s=0,g=0;
cin>>a;
for(int i=1;i<=a;i++){
int b;
char c;
cin>>b>>c;
s=s+b;
for(int j=1;j<=b;j++)
 d[j+s]=c;}
 for(int i=1;i<=s/2;i++)
 {if(d[i]!=d[s+1-i])
 g++;
 }
 cout<<g;
 return 0;
}
