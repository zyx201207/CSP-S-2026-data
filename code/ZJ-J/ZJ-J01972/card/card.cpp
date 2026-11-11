#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
int b[500005];
int f[500005];
int d[500005];
void putint(int x){
    if(x<10){
        putchar(x+'0');
        return;
    }
    putint(x/10);
    putchar(x%10+'0');
}
int main(){//[HOPES] and [DREAMS]
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    a[n+1]=0;
    for(int i=1;i<=n;i++){
        f[i]++;
        ans[a[i]]+=f[i];
        f[b[a[i]]+1]+=f[i];
    }
    for(int i=1;i<=m;i++){
        putint(ans[i]);putchar(' ');
    }
    return 0;
}//green for 0.4h
/*
Maybe you want to find something interesting here?
For example:
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
or
int mian(){
    return 0;
}
?

Now's your chance to be a BIG SHOT!
*/