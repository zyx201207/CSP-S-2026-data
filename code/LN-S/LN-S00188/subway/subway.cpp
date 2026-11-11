#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,sum;
int w[500005],k[505],a[505][500005],t[505][500005],r[2005][2005];
int ex(int l,int y,int num){
    for(int f=1;f<=n;f++){
        for(int i=1;i<=k[f];i++){
            if(a[f][i]==l){
                for(int j=i+1;j<=k[f];j++){
                    if(sum==a[f][j]){
                        continue;
                    }sum=l;
                    if(a[f][j]==y){
                        if(ans>num+r[a[f][i]][y]){
                            ans=num+r[a[f][i]][y];
                        }
                        return num+r[a[f][i]][y];
                    }else{
                        ex(a[f][j],y,num+r[a[f][i]][a[f][j]]);
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int f=1;f<=n;f++){
        for(int i=1;i<=k[f];i++){
            for(int j=i+1;j<=k[f];j++){
                r[a[f][i]][a[f][j]]=t[f][i]+t[f][j];
                r[a[f][j]][a[f][i]]=r[a[f][i]][a[f][j]];
            }
        }
    }
    for(int f=1;f<=q;f++){
        int x,y;
        cin>>x>>y;
        ans=999999999;
        int l=x,num=0;
        ex(l,y,num);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
