#include <bits/stdc++.h>
using namespace std;
int n,m,d,b[300005],now;
int c[300005][2],k;
vector<int> a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        a.push_back(d);
    }
    for(int i=0;i<n;i++){
        memset(c,0,sizeof(c));
        for(int j=i;j<n;j++){
            now = a[j];
            if(c[now][1]==1){

            }else if(c[now][0]==1){
                c[now][1] = 1;
            }else{
                c[now][0] = 1;
            }
        }
        k=0;
        for(int j=i;j<n;j++){
            if(c[a[j]][1]==1){
                if(k==0) k=1;
                else k=0;
            }
            if(k==0){
                b[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",b[i]);
    }
    return 0;
}
