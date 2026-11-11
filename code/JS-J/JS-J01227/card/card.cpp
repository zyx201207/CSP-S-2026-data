#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],c[N],cnt;
int b[M],ans[M];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool fA=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) fA=0;
    }
    if(fA){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans[a[j]]=j;
            }
        }

        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        cnt=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                for(int k=b[a[j]];k<=cnt;k++){
                    b[c[k]]=0;
                }
                cnt=0;
            }
            cnt++;
            b[a[j]]=cnt;
            c[cnt]=a[j];
        }
        //for(int i=1;i<=cnt;i++){
        //    cout<<c[i]<<' ';
        //}
        //cout<<'\n';
        for(int i=1;i<=m;i++){
            if(b[i])
                ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
