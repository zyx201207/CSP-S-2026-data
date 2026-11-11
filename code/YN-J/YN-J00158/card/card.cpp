#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=3e5+5;
int n,m,a[N],ans[M],last[M];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;++i){
        int lst=last[a[i]];
        while(lst<=n){
            lst=last[a[lst]];
            ans[a[lst]]++;ans[a[lst]]=min(ans[a[lst]],n);
            lst++;
        }
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
    return 0;
}
/*
lst~now-1不留
cnt[lst~now-1]-=1
O(n)算答案
链表？

第一个次数为last，最后一个为n
*/
//7 5 1 1 2 2 3 4 5
