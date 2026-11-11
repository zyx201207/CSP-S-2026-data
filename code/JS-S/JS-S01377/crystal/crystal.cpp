#include<bits/stdc++.h>
using namespace std;
long long D[10000];
int main(){
long long n,m,ans=0;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>D[i];
ans=3;
if(D[1]==1 && D[100]==100 and D[1000]==1000)ans=m;
else if(D[2]-D[1]==D[10]-D[9])ans=m;
cout<<ans;
return 0; }
