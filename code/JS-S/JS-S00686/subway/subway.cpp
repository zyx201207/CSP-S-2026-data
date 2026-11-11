#include <bits/stdc++.h>
using namespace std;
long long c[1010][1010],f[1010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long h,n,m,p,q,t=0,i,j,k,x1,f1,x2,f2;
    cin>>h>>n>>m>>p>>q;
    for(i=1;i<=1010;i++){
        for(j=1;j<=1010;j++){
            c[i][j]=1061109567;
        }
    }
    for(i=1;i<=m;i++){
        cin>>f[i];
    }
    for(i=1;i<=n;i++){
        cin>>k>>x1>>f1>>x2>>f2;
        c[x1][x2]=min(c[x1][x2],f1+f2);
        c[x2][x1]=min(c[x2][x1],f1+f2);
    }
    for(i=1;i<=m;i++){
        c[i][i]=0;
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<=q;i++){
        cin>>x1>>f1;
        cout<<f[x1]+f[f1]+c[x1][f1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
