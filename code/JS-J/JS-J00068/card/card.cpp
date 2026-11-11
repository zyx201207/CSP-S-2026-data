#include <bits/stdc++.h>
using namespace std;


int a[500010];
int query(int n){
    for(int i=n-1;i;i--){
        if(a[i]==a[n]){
            return i;
        }
    }
    return 0;
}
int cnt[300010];
int n,m;
int front[500100],en[500010],last[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=query(i);
    }
    for(int i=1;i<=n;i++){
        memset(front,0,sizeof(front));
        memset(en,0,sizeof(en));
        for(int j=1;j<=n;j++){
            last[a[j]]=query(i);
        }
        int rear=0;
        for(int j=i;j<=n;j++){
            if(last[a[j]]&&last[a[j]]>=i){
                front[++rear]=last[a[j]];
                en[rear]=j;
                int l=last[a[j]];
                while(l<=j){
                    l++;
                    last[a[l]]=0;
                }
                last[a[j]]=j;
            }else{
                last[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            bool ok=true;
            for(int k=1;k<=rear;k++){
                if(front[k]<=j&&j<=en[k]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cnt[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;

}
