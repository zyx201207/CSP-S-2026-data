#include<bits/stdc++.h>
using namespace std;
int c[400000],d[400000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","r",stdout);
int a,b;
cin>>a>>b;
for(int i=1;i<=a;i++){
cin>>d[i];
c[i]=d[i];
}
if(b==1)
{sort(c,c+a+1);
cout<<c[1];}
else
sort(c,c+a+1);
}
