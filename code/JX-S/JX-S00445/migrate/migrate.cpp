#include<bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t,n;
long long d;
long long x[N],f[N],g[N];
int st=0;
long long readll(){
    long long p,res=0;
    bool neg=false;
    while(p!=EOF&&(p<'0'||p>'9')){
        p=getchar();
        if(p=='-')neg=true;
    
    }
    while(p!=EOF&&('0'<=p&&p<='9')){
        res=res*10+p-'0';
        p=getchar();
    
    }
    if(neg)res=-res;
    return res;
}
int read(){
    int p,res=0;
    bool neg=false;
    while(p!=EOF&&(p<'0'||p>'9')){
        p=getchar();
        if(p=='-')neg=true;
    
    }
    while(p!=EOF&&('0'<=p&&p<='9')){
        res=res*10+p-'0';
        p=getchar();
    
    }
    if(neg)res=-res;
    return res;
}
long long res;
void sol(){
    n=read(),d=readll();
    for(int i=1;i<=n;i++){
        x[st+i]=readll();
    }
    res=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[st+j]=0;
            g[st+j]=N+2;
        }
        f[st+i]=1,g[st+i]=0;
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(x[st+k]-x[st+j]>d){
                    break;
                }
                if(g[st+k]>g[st+j]+1){
                    g[st+k]=g[st+j]+1;
                    f[st+k]=0;
                }
                if(g[st+k]==g[st+j]+1){
                    f[st+k]+=f[st+j];
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(f[st+j]==2){
                res++;
            }
        }
    }
    cout<<res<<"\n";
    st+=n;
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        sol();}
}