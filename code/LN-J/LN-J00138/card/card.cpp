#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],m,c[500005],d[500005],e[500005],f[500005],jl;
int lo(int x){
    return x&(-x);
}
void cr(int x,int y){
    while(x<=n){
        f[x]+=y;
        x+=lo(x);
    }
}
int js(int x){
    int ans=0;
    while(x){
        ans+=f[x];
        x-=lo(x);
    }
    return ans;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        for(int j=1;j<=n;j++){
            if(e[a[j]])d[j-1]=e[a[j]];
            e[a[j]]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[j]=b[j]=0;
            }
            cr(i,1);
            for(int j=i+1;j<=n;j++){
                 if(d[j]&&d[j]>=i&&js(d[j]))cr(d[j],-1),cr(j+1,1);
            }
            jl=0;
            for(int j=i;j<=n;j++){
                jl+=f[j];
                if(jl>0)b[a[j]]=1;
            }
            for(int j=1;j<=n;j++){
                c[j]+=b[j];
                //cout<<b[j]<<' '<<j<<' '<<i<<'\n';
            }
        }
        for(int i=1;i<=m;i++)
        cout<<c[i]<<' ';
    }
    return 0;
}

