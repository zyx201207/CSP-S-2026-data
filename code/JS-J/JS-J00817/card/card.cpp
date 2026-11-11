#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],b[M];
bool isA,ok[M];
int vis[M],stk[M],top;
int cnt[N];
void check(int k) {
    for(int i=1;i<=m;++i)vis[i]=0;
    top=0;
    for(int i=k;i<=n;++i) {
        if(vis[a[i]]) {
            while(stk[top]!=a[i]) {
                vis[stk[top]]--;
                top--;
            }
        } else {
            vis[a[i]]++;
            stk[++top]=a[i];
        }
    }
    for(int i=1;i<=top;++i) {
        cnt[stk[i]]+=b[a[k]];
    }
}
void solveA() {
    for(int i=1;i<=n;++i) {
        b[a[i]]=i;
    }
    for(int i=1;i<=m;++i) {
        printf("%d ",b[i]);
    }
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    isA=true;
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if(i>1&&a[i]<a[i-1])isA=false;
        b[a[i]]++;
    }
    if(isA) {
        solveA();
        return 0;
    }
    for(int i=1;i<=m;++i)ok[i]=true;
    for(int i=n;i>=1;--i) {
        if(ok[a[i]]) {
            check(i);
            ok[a[i]]=false;
        }
    }
    for(int i=1;i<=m;++i)printf("%d ",cnt[i]);
    return 0;
}
