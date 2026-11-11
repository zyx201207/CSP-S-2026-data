#include <bits/stdc++.h>
using namespace std;
int n,m,a[500002],d[500002];
int main(){
    cin>>m>>n;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(int i=1;i<=n;i++){
        int l,r;int ans=0;
        if(r==1){cout<<0;break;}
        cin>>l>>r;
        int j1;
        for(int j=1;j<=l;j++){cin>>a[i];j1=j;}
        for(int i1=1;i<l;i1++){d[i1]=a[i1+1]-a[i1];}
        j1-=1;
        while(r>d[j1])
            j1--;

        int cnt;
        cnt=r+2;
        ans=(cnt/(r*r))*(l-r-1);
            cout<<ans<<endl;}
        return 0;
}
