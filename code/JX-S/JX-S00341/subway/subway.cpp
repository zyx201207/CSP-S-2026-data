#include<bits/stdc++.h>
using namespace std;
struct xy{
    int zt;
    int f;
}a[500005];
struct xy1{
    int h,zta;
};
struct{
    xy1 a2[500005];
    int k;
}a1[505];
int b[500005];
int c,n,m,d,q;
long long cnt,ans;
void dfs(int x,int y,int d,int z){
    if(x==y){
        ans=min(ans,1ll*cnt+1ll*a[a1[d].a2[z].h].zt);
        return;
    }
    for(int i=z;i<=a1[d].k;i++){
        dfs(a1[d].a2[i].h,y,d,i);
        if(b[a1[d].a2[i].h]>1){
            cnt+=a1[d].a2[z].zta;
            for(int i=d+1;i<=n;i++){
                for(int j=1;j<=a1[i].k;j++){
                    if(a1[i].a2[j].h==x){
                        cnt+=a1[d].a2[j].zta;
                        dfs(x,y,i,j);
                        cnt-=a1[d].a2[j].zta;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i].zt;
    }
    int k1;
    for(int i=1;i<=n;i++){
        cin>>k1;
        a1[i].k=k1;
        for(int j=1;j<=k1;j++){
            cin>>a1[i].a2[j].h>>a1[i].a2[j].zta;
            b[a1[i].a2[j].h]++;
        }
    }
    int x,b;
    while(q--){
        cin>>x>>b;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a1[i].k;j++){
                if(a1[i].a2[j].h==x){
                    cnt=a[a1[i].a2[j].h].zt+a1[i].a2[j].zta;
                    dfs(x,b,i,j);
                }
            }
        }
        cout<<ans<<"\n";
        ans=0;
        cnt=0;
    }
    return 0;
}
