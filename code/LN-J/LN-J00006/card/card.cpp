#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N],pos[N],ju[N],sum[N];
bool v[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int k=0;k<=n;k++){
        memset(v,0,sizeof(v));
        memset(pos,0,sizeof(pos));
        memset(ju,0,sizeof(ju));
        int p=0;
        for(int i=k;i<n;i++){
            int cur=a[i];
            if(!v[cur]) ju[p++]=cur,pos[cur]=p,v[cur]=1;
            else{
                for(int i=p-1;i>=pos[cur];i--){
                    p--,v[ju[p]]=0,pos[ju[p]]=0;
                }
            }
            //for(int i=0;i<p;i++) cout<<ju[i]<<' '<<v[cur]<<' ';
            //cout<<'\n';
        }
        for(int i=1;i<=m;i++) sum[i]+=(int)v[i];
    }
    for(int i=1;i<=m;i++) cout<<sum[i]<<' ';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
