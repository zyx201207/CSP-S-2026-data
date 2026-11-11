#include<bits/stdc++.h>
using namespace std;
int sj[400000],pa[500000];
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,pi=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>sj[i];
    }
    for(int x=1;x<=m;x++){
         for(int i=x;i<=m;i++){
                for(int j=m,o;j>i;j--){
                if(sj[j]==sj[i]){
                     pi++;
                     pa[pi]=sj[j];
                 }
                 i=j;
             }
         }
    }
    for(int i=1;i<=pi;i++){
        cout<<pa[i];
    }
    for(int i=1,zs=0;i<=n;i++){
        for(int j=1;j<=pi;j++){
            if(pa[j]==i){
                zs++;
            }
        }
        cout<<zs<<' ';
        zs=0;
    }
    return 0;

    fclose(stdin);
    fclose(stdout);

}
