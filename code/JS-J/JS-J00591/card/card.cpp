#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[300050],ma[550],mn[550],mid;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n>500){
        for(int i=1;i<=n;i++){
            b[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            printf("%d ",b[i]);
        }
    }
    else{
        memset(ma,0,sizeof(ma));
        for(int i=1;i<=n;i++){
            memset(mn,0,sizeof(mn));
            mid=0;
            for(int j=i;j<=n;j++){
                for(int k=1;k<=mid;k++){
                    if(a[j]==mn[k]){
                        for(int x=k+1;x<=mid;x++){
                            mn[x]=0;
                        }
                        mid=k;
                    }
                    else{
                        mid++;
                        mn[mid]=a[j];
                    }
                }
                for(int k=1;k<=mid;k++){
                    ma[mn[k]]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d ",ma[i]);
        }
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
