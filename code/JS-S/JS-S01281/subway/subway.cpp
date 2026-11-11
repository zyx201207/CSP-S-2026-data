#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct memoir{
    int t[500005];
    int s[500005];
}o[505];
struct rien{
    ll x;
    ll y;
}r[100005];
ll c,n,m,d,q,w[500005],u[505],ans=0,p;
bool z=0,v=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>u[i];
        for(int j=1;j<=u[i];j++){
            cin>>o[i].s[j];
            cin>>o[i].t[j];
        }
    }
    for(int i=1;i<=q;i++){
        ans=0;
        cin>>r[i].x>>r[i].y;
        p=w[r[i].x]+w[r[i].y];
        for(int j=1;j<=n;j++){
            if(o[j].t[r[i].x]!=0&&o[j].t[r[i].y]!=0){
                if(z==1) ans=min(ans,p+o[j].t[r[i].x]+o[j].t[r[i].y]);
                else{
                    ans=p+o[j].t[r[i].x]+o[j].t[r[i].y];
                    z=1;
                }
            }
            if(o[j].t[r[i].x]!=0&&z==0&&o[j].t[r[i].y]==0){
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=m;l++){
                        if(o[k].t[r[i].y]!=0&&o[k].t[l]!=0&&o[j].t[l]!=0){
                            if(v==1) ans=min(ans,p+o[j].t[r[i].x]+o[j].t[l]+o[k].t[l]+o[k].t[r[i].y]);
                            else ans=p+o[j].t[r[i].x]+o[j].t[l]+o[k].t[l]+o[k].t[r[i].y];
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
