#include<bits/stdc++.h>
using namespace std;
bool k[510][500010];
int a[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,ans=0,enans=0x3f3f3f3f;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    int t;
    for(int i=1;i<=n;i++){
        int z;
        scanf("%d",&z);
        for(int j=1;j<=2*z;j++){
            int a;
            scanf("%d %d",&a,&t);
            k[i][a]=1;
        }
    }
    for(int i=1;i<=q;i++){
        int st,en;
        scanf("%d %d",&st,&en);
        for(int j=1;j<=n;j++){
            if(k[j][st] && k[j][en]){
                ans=a[st]+t+t+a[en];
                enans=min(enans,ans);
            }
        }
    }
    cout<<enans;
    return 0;
}
