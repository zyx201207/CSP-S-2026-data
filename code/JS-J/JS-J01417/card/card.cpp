#include<bits/stdc++.h>
using namespace std;

long long a[1000004];
long long pre[1000004];
long long pos;
long long nxt[1000004];
long long cnt[1000004];
long long t[1000004];
long long get(int x){
    return t[x];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(pre[a[i]]==0){
            pre[a[i]]=i;
        }else{
            nxt[pre[a[i]]]=i;
            pre[a[i]]=i;
        }
    }
    int j=1;
    for(int i=1;i<=n;i++){
        t[i]+=1;
        if(nxt[i]!=0){
            t[nxt[i]]+=t[i];
            t[i]=0;
        }else{
            t[i+1 ]+=t[i];
        }
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]+=get(i);
    }
    for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
    }
    return 0;
}
