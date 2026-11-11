#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005],x[500005],y[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int v=1;v<=m;v++){
        cin>>w[v];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    while(q--){
        int num;
        num=w[x[q]]+w[y[q]];
        int xe=0,xf=1000,ye=0,yf=1000;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x[q]){
                    if(t[i][j]<xf){
                        xe=i,xf=j;
                    }
                }
                 if(a[i][j]==y[q]){
                    if(t[i][j]<yf){
                        ye=i,yf=j;
                    }
                }
            }
        }
        if(xe==ye){
            num=num+xf+yf;
            cout<<num;
        }
        else{
            char flag=false;
            for(int j=1;j<=max(k[xe],k[ye]);j++){
                if(a[xe][j]==a[ye][j]){
                    num=num+t[xe][j]+t[ye][j];
                    flag=true;
                }
            }
            if(flag){
                cout<<num;
            }
            else{
                for(int i=1;i<=n;i++){
                    char fa=false,tr=false;
                    int fi,fj,fc,ti,tj,tc;
                    for(int j=1;j<=k[i];j++){
                            for(int c=1;c<=k[i];c++){
                                if(a[i][j]==a[xe][c]){
                                    fa=true;
                                    fi=i,fj=j,fc=c;
                                }
                                if(a[i][j]==a[ye][c]){
                                    tr=true;
                                    ti=i,tj=j,tc=c;
                                }
                            }
                    }
                    if(fa&&tr){
                        num=num+t[xe][fc]+t[ye][tc]+t[fi][fj]+t[ti][tj]+t[fi][tj]+t[ti][fj];
                        cout<<num;
                        break;
                    }
                }
            }
        }
    }
}
