#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,l,r;
int w[505];
long long ma[500005][500005]={0};
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++)cin>>w[i];
int a[500005],t[500005];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
            cin>>a[i]>>t[i];
for(int o=1;o<=k;o++){
    for(int p=o+1;p<=k;p++)
    ma[a[o][a[p]]+=t[o]+t[p],ma[a[p]][a[o]]+=t[o]+t[p];;
}


for(int i=1;i<=q;i++){

cin>>l>>r;
cout<<ma[l][r]+w[l]+w[r];
}
return 0;
}
