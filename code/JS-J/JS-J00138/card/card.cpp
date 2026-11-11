#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int a[MAXN],b[MAXN],vh1[MAXN],n,m;
bool vh2[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",b+i);
    for(int i=1;i<=n;++i){
        /*printf("%d------\n",i);*/
        for(int j=1;j<=n;++j)/*a[j]=b[j],*/vh2[j]=false;
        int len=0,pos=-1;
        for(int j=i;j<=n;++j){
            bool fin=false;
            for(int k=1;k<=len;++k)
                if(a[k]==b[j]){
                    pos=k;
                    fin=true;
                    break;
                }
            if(fin)len=pos;
            else a[++len]=b[j];
            /*printf("%d:\n",b[j]);
            for(int k=1;k<=len;++k)printf("%d ",a[k]);
            printf("\n");*/
        }
        for(int j=1;j<=len;++j)if(!vh2[a[j]])++vh1[a[j]],vh2[a[j]]=true;
    }
    for(int i=1;i<m;++i)printf("%d ",vh1[i]);
    printf("%d",vh1[m]);
    printf("\n");
    return 0;
}