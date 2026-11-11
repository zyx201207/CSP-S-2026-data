#include<bits/stdc++.h>
using namespace std;
long long a[5001][5001];
long long w[50001];
long long n,m,d,q,ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long x,y;
            cin>>x>>y;
            a[m+i][x]=a[x][m+i]=y;
        }
    }
    for(int i=1;i<=n+m;i++)
        for(int j=n+m;j>=1;j--)
            if(i!=j)
                for(int k=1;k<=n+m;k++){
                    if(a[i][k]&&a[j][k])
                        if(a[i][j]==0||a[i][j]>a[i][k]+a[k][j])
                            a[j][i]=a[i][j]=a[i][k]+a[k][j];
            }
    while(q--){
        long long st,en;
        cin>>st>>en;
        cout<<w[st]+w[en]+a[st][en]<<endl;
    }
    return 0;
}
