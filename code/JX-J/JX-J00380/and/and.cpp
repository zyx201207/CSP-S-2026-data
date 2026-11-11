#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[200005];
void dfs(int js,int lsq,long long z){
    if(z<maxn) return;
    if(lsq==m){
        maxn=max(maxn,z);
        return;
    }
    if(lsq==0){
        for(int i=js;i<=n;i++){
            dfs(i+1,lsq+1,a[i]);
        }
    }else{
        for(int i=js;i<=n;i++){
            dfs(i+1,lsq+1,(z&a[i]));
        }
    }
    
    return;
}
inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'&&c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    dfs(1,0,0);
    cout<<maxn;
    return 0;
}
