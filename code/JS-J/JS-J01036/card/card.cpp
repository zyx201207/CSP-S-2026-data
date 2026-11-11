#include<bits/stdc++.h>
using namespace std;
int c[500005],ans[300005],n,m,p,x[500005],f[300005],d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i-d];
        if(x[i-d]==x[i-d-1])
            d++;
    }
    for(int q=1;q<=n;q++){
        p=0;
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        for(int i=q;i<=n;i++){
            if(!f[x[i]]){
                c[++p]=x[i];
                f[x[i]]=p;
            }else{
                for(int j=p;j>f[x[i]];j--)
                    f[c[j]]=0;
                p=f[x[i]];
            }
        }
        for(int j=1;j<=p;j++){
                //cout<<c[j]<<" ";
                ans[c[j]]++;
            }
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
