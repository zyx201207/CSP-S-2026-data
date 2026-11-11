#include<bits/stdc++.h>
using namespace std;
#define int long long
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5e5+5;
int n,m,a[N],cnt[N],stk[N],ans[N],id[300005],nxt[N],b[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool flag=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        if(a[i]<a[i-1]){
            flag=0;
        }
    }
    if(n<=5000){
    for(int i=1;i<=n;i++){
        int top=0;
        memset(cnt,0,sizeof cnt);
       for(int j=i;j<=n;j++){
            if(cnt[a[j]]){
                while(stk[top]!=a[j]){
                    cnt[stk[top--]]--;
                }
            } else{
                cnt[stk[++top]=a[j]]++;
            }
       }
       for(int j=1;j<=m;j++){
            if(cnt[j]){
                ans[j]++;
            }
       }
       //cerr<<"i: "<<i<<'\n';
       //for(int j=1;j<=top;j++){
       // cerr<<stk[j]<<" ";
       //}cerr<<'\n';
    }
    for(int i=1;i<=m;i++){
        printf("%lld",ans[i]);

            if(i<m){
                printf(" ");
            }
    }printf("\n");}
    else if(n*m<=1000000000){
        //nxt[i] lst[i] => j
        //id[number] =>number's latest position
        for(int i=1;i<=n;i++){
            nxt[id[a[i]]]=i;
            //lst[i]=id[a[i]];
            id[a[i]]=i;
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
            while(nxt[j]){
                j=nxt[j];
            }ans[a[j]]++;}
        }
        for(int i=1;i<=m;i++){
            printf("%lld",ans[i]);
            if(i<m){
                printf(" ");
            }
        }
        printf("\n");
    }
    else if(flag){

    for(int i=1;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            b[a[i-1]]=i-1;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld",b[i]);
            if(i<m){
                printf(" ");
            }
    }printf("\n");
    } else{
        for(int i=1;i<=n;i++){
            nxt[id[a[i]]]=i;
            //lst[i]=id[a[i]];
            id[a[i]]=i;
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
            while(nxt[j]){
                j=nxt[j];
            }ans[a[j]]++;}
        }
        for(int i=1;i<=m;i++){
            printf("%lld",ans[i]);
            if(i<m){
                printf(" ");
            }
        }
        printf("\n");
    }
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
//add the new role's card to the bottom of the desktop
//if there's a same card in the old queue
//delete the front of the queue to the same card ?
//no the problem's introduction has something wrong...
//the old card queue should be the bottom of the new card queue
//record the first and the last position of each number
//seem not to be so easy
//no that completely wrong
//why?
//clear the old queue!!!
//
