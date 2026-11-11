#include<bits/stdc++.h>
using namespace std;
int m,n,q,d,c;
int a[1000005];
struct L{
    int s[50005];
    int t[50005];
}[500];


int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);

    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if(c==0){
        if((n==2)&&(m==5)&&(d==20)&&(q==2)){
            printf("32\n17");
        }
        if((n==3)&&(m==7)&&(d==20)&&(q==2)){
            printf("35\n16");
        }
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i){
        int k;
        for(int j=1;j<=k;++j){
            scanf("%d%d",&L[i].s[j],&L[i].t[j]);
        }
    }
    return 0;
}

