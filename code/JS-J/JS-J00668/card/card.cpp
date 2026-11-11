#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=5e5+5,M=3e5+5;

int a[N],b[N];
int p[M];
int c[N];
int ans[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>0;i--){
        if(!p[a[i]]) p[a[i]]=i;
        b[i]=p[a[i]];
        c[i]=1;
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=c[i];
        c[b[i]+1]+=c[i];
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}
