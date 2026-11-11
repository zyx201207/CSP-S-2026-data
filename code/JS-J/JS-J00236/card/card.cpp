#include<bits/stdc++.h>
using namespace std;
int  a[500010],cnt[300010],g[500010],t[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        t[i]=i;
        for(int j=i+1;j<=n;j++){
            if(a[j]==a[i]){
                t[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {g[j]=a[j];}

        for(int j=t[i];j<=n;j++){
            cnt[g[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }

    return 0;
}

