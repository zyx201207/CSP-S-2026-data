#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,arr[505][105],t[500005],err[505],t2[505][105],brr[100005],crr[100005],f[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)   cin>>t[i];
    for(int i=1;i<=n;i++){
        cin>>err[i];
        for(int j=1;j<=err[i];j++){
            cin>>arr[j][i]>>t2[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=err[i];j++){
            for(int x=j;x<=err[i];x++){
                f[arr[j][i]][arr[x][i]]=t2[j][i]+t2[x][i];
                f[arr[x][i]][arr[j][i]]=t2[j][i]+t2[x][i];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>brr[i]>>crr[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<f[brr[i]][crr[i]]+t[brr[i]]+t[crr[i]]<<endl;
    }
}
//
