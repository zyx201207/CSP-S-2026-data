#include<bits/stdc++.h>
using namespace std;
int n,m,pos=1;
int a[500010];
int cnt[300010];
int q[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        q[pos++]=a[i];
        for(int j=i+1;j<=n;j++){
            int p=q[1];
            if(a[j]==p){
                memset(q,0,sizeof(q));
                pos=1;
            }
            q[pos++]=a[j];
        }
        for(int i=1;i<=pos;i++){
            cnt[q[i]]++;
        }
        pos=1;
        memset(q,0,sizeof(q));
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
