#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],cnt[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=cnt[a[i]];
        cnt[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++){
        int l=0,c[N];
        for(int j=i;j<=n;j++){
            if(b[j]>=i){
                int p=INT_MAX;
                for(int k=l;k>=1;k--)
                    if(c[k]==a[j]){
                        p=k;
                        break;
                    }
                if(p<=l)
                    l=p;
            }
            else
                c[++l]=a[j];
        }
        bool vis[M];
        for(int j=1;j<=m;j++)
            vis[j]=0;
        for(int j=1;j<=l;j++)
            vis[c[j]]=1;
        for(int j=1;j<=m;j++)
            if(vis[j])
                cnt[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}
