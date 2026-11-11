#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,x[N],d;
void dfs(int p,int end,int jmp,int dep,int &sol,int &len) {
    if (p==end) {
        if (dep<len) len=dep,sol=1;
        else if (dep==len) sol++;
        return ;
    }
    for (int i=p+1;x[p]+jmp>=x[i] && i<=end;i++) dfs(i,end,jmp,dep+1,sol,len);
}
void solve() {
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>x[i];
    int ans=0;
    for (int u=1;u<n;u++) {
        for (int v=u+1;v<=n;v++) {
            int cnt=0,mn=0x7fffffff;
            dfs(u,v,d,0,cnt,mn);
            if (cnt==2) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--) solve();
    return 0;
}
/*
It's easy to find that we shouldn't and mustn't jump backwards since it won't be the shortest path between u and v.
O(n^2) to choose the u and v and then dfs checking its depth
*/
/*
I have an idea.
Maybe there is and only is a structure like THIS(you can see it in the following paragraph) between u and v if u,v are a pair of Double Pathed Island Pair.
But is it right? I had to prove it.
THIS:
  |-----------|
--1---2- ... -3---4--
      |-----------|
(it's possible for the 1 to jump to the 3 but not 4, and possible for the 2 to jump to the 4)
*/
/*
Prove:(The THISs shouldn't be covered by a bigger THIS for it'll be short-pathed(how is the word Duan3Lu4 spelled??))
    if there's no THIS, there's only one shortest path,so it's not a DPIP(Double Pathed Island Pair);
    if there are two or more (k) THISs, there would be k choices resulting with 2^k shortest paths, so it's also impossible.
*/
/*
I found a opposite solution. F**king CCF. I'd write my dfs.
*/
/*
maybe true THIS should be 
  |---------|
--1- ... -2-3- ... -4--
          |---------|

Oh s**t there's no enough time.
*/
/*
S**T.
*/
/*
I am ROBIN's DOG!!!
Miss ROBIN!!! I am your fans!!!
This is true music!
*/