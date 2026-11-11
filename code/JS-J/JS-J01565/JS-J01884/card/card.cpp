#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],d[300005],e[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        for(int j=i;j<=n;j++){
            if(b[a[j]]!=0){
                d[b[a[j]]+1]--;d[j+1]=1;
            }
            b[a[j]]=j;
        }
        for(int j=i+1;j<=n;j++){
            if(d[j-1]==-1&&d[j]==0) d[j]=-1;
            else if(d[j-1]==-1&&d[j]==1) d[j]+=d[j-1];
            cout<<d[j]<<" ";
        }
        cout<<endl;
        for(int j=i;j<=n;j++){
            if(d[j]==0){
                if(e[a[i]]==0){
                    c[a[i]]++;
                    e[a[i]]=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
