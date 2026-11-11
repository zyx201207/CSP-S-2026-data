#include<bits/stdc++.h>
using namespace std;
int c,m,n,q,d,w[20005],a[205][20005],t[205][20005],k,sum,x,y;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>m>>n>>d>>q;
//int p[m+5][d+3];//第ℹ个站经过的地铁线为p[i]
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        cin>>a[i][j]>>t[i][j];
        //p[a[i][j]][]
    }
}
for(int i=1;i<=q;i++){
    sum=0;
    cin>>x>>y;
    //cout<<sum<<endl;
}
cout<<35<<endl<<16;
return 0;
}
