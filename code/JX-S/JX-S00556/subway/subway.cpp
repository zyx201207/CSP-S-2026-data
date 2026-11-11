#include<bits/stdc++.h>
using namespace std;
int t[10050],t1[505][505],d[505][505],x[505],p[1050][1050];
inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-1') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
int dfs(){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) t[i]=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
        for(int j=1;j<=x[i];j++){
            int y=read();
            t1[i][j]=read();
        }
    }
    while(q--){
        int x=read(),y=read(),sum=t[x]+t[y],f,g;
        printf("%d\n",sum);
    }
    return 0;
}
