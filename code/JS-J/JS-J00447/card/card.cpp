#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}int n,m;
int a[500010];
int nxt[500010];
int lst[500010];
int b[500010];
int cnt[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1; i<=n; i++){
        a[i]=read();
        nxt[lst[a[i]]]=i;
        lst[a[i]]=i;
    }nxt[0]=0;
    for(int i=2; i<n; i++){
        int j=i-1;
        while(nxt[j]<i&&j>0) j=b[j];
        b[i]=j;
    }
    //for(int i=1; i<=n; i++) cout<<nxt[i]<<' ';
    //cout<<endl;
    //for(int i=1; i<=n; i++) cout<<b[i]<<' ';
    //cout<<endl;
    for(int i=1; i<=n; i++){
        if(b[i]==0) cnt[a[i]]=i-b[i];
        else{
            cnt[a[i]]+=i-b[i];
        }
    }for(int i=1; i<=m; i++) cout<<cnt[i]<<' ';
}