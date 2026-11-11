#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],t[5005][5005];
long long a[5005][5005],k[5005],s[5005];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++) cin>>w[i];
    for(int i = 1;i<=n;i++){
        cin>>k[i];
        for(int j = 1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(a[i][j]==i) s[i]=t[i][j];
        }
    }
    while(q--){
        long long xr,yr,time[500005];
        cin>>xr>>yr;
        for(int i = 1;i<=m;i++) time[i]=s[i];
        for(int i = xr;i<=n;i++){
            for(int j = 1;j<=k[i];j++){
                time[a[i][j]]=min(t[i][j]+time[i],time[a[i][j]]);
            }
            time[i]+=s[i];
        }
        for(int i = 1;i<=xr;i++){
            for(int j = 1;j<=k[i];j++){
                time[a[i][j]]=min(t[i][j]+time[i],time[a[i][j]]);
            }
            time[i]+=s[i];
        }
        cout<<time[yr]+w[yr]+w[xr]<<"\n";
    }
}
