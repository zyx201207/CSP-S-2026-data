#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll id=0,n,m,a[200005],ans;
struct Trie{
    ll to[2],have;
}trie[4000006];
void more(int need,int way){
    id++;
    trie[need].to[way]=id;
    trie[id].have=0;
    trie[id].to[0]=0;
    trie[id].to[1]=0;
}
void build(ll need){
    ll now=0;
    for (int i=30;i>=0;i--){
        if ((1<<i)&need){
            if (trie[now].to[1]==0) more(now,1);
            now=trie[now].to[1];
            trie[now].have++;
        }
        else{
            if (trie[now].to[0]==0) more(now,0);
            now=trie[now].to[0];
            trie[now].have++;
        }
    }
}
ll query(ll now,ll sum,ll deep){
    if (now!=0 && trie[now].have<sum) return 0;
    ll q=0;
    if (trie[now].to[1]!=0 && trie[trie[now].to[1]].have>=sum){
        if (deep==0) return 1;
        else q=(1<<deep)+query(trie[now].to[1],sum,deep-1);
    }
    else{
        if (deep==0) return 0;
        if (trie[now].to[1]==0) q=q+query(trie[now].to[0],sum,deep-1);
        else{
            ll child=0;
            for (int i=1;i<sum;i++){
                child=max(child,query(trie[now].to[0],i,deep-1)&query(trie[now].to[1],sum-i,deep-1));
            }
            child=max(child,query(trie[now].to[0],sum,deep-1));
            q+=child;
        }
    }
    return q;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    trie[0].have=0;
    trie[0].to[0]=0;
    trie[0].to[1]=0;
    for (int i=1;i<=n;i++){
            cin>>a[i];
            build(a[i]);
    }
    ans=query(0,m,31);
    cout<<ans/2;
}
