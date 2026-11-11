#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],f[41];
bool calc(int x,int y){
    int ret=x&y;
    return ret==y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=30;i++){
        for(int j=1;j<=n;j++)
            if(a[j]&(1<<i))
                f[i]++;
    }
    int idx=0;
    int id=0;
    for(;;){
        id=-1;
        for(int i=30;i>=0;i--)
            if(f[i]>=m){
                id=i;
                break;
            }
        if(id==-1){
            printf("%d\n",idx);
            return 0;
        }
        idx+=(1<<id);
        for(int i=0;i<=30;i++)
            f[i]=0;
        for(int i=1;i<=n;i++)
            if(calc(a[i],idx)){
                for(int j=0;j<30;j++){
                    int s=a[i]-idx;
                    if(s&(1<<j))
                        f[j]++;
                }
            }
    }

    return 0;
}
