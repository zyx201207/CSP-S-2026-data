#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,a[10000];
cin>>n>>m;
for(int i=1;i<=n;i++)
    cin>>a[i];
for(int i=1;i<m;i++)
    cout<<i<<' ';
cout<<m;
return 0;}
