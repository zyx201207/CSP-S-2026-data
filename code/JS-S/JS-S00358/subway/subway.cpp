#include<bits/stdc++.h>
using namespace std;
long long n,m,A[405][405],d,c,q,b[405],a1[405],w[405][405];
int qread(){
    int x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) {
        if(c=='-') f=-1;
    }
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
/*
int erfeng(long long x){

}
 */

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = qread();n = qread();m = qread();d = qread();q = qread();
    for(int i=1;i<=m;i++){
        b[i]=qread();
    }
    for(int i=1;i<=n;i++){
        int k=qread();
        for(int j=1;j<=k;j++){
            a1[j]=qread();w[a1[j]][i]=qread();
        }
        for(int j1=1;j1<=k;j1++){
            for(int j2=1;j2<=k;j2++){
                A[a1[j1]][a1[j2]]=1;
            }
        }
    }

    return 0;
}

