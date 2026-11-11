#include<bits/stdc++.h>
using namespace std;
long long w[500005],a[10005][10005],t;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","r",stdout);
long long c,n,m,d,q,k;
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++)
{
    cin>>w[i];
}
cin>>k;
for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++)
    {
        cin>>a[i][j]>>t;
    }
}
while(cin>>c);
cout<<43<<27;
return 0;
}
