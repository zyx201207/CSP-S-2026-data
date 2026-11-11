#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],x[200009],f[200009],ans[200009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        memset(x,0,sizeof(x));
        int to=0;
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                to++;
            }
            x[j]=to;
        }
        if(a[n]>1){
            int l[200005],r[200005],cnt=0;
            bool flag=0;
            for(int j=1;j<=n;j++){
                if(x[j]!=x[j-1]&&j!=1){
                    flag=!flag;
                    if(flag){
                        l[++cnt]=j;
                    }else{
                        r[cnt]=j;
                        j--;
                    }
                }
            }
            cnt--;
            for(;cnt>0;cnt--){
                for(int j=l[cnt];j<r[cnt];j++){
                    f[j]=max(f[j],l[cnt]);
                }

            }
        }
    }
    bool tf[200009];
    for(int i=1;i<=n;i++){
        memset(tf,0,sizeof(tf));
        for(int j=i;j<=n;j++){
            if(f[j]<i){
                tf[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(tf[j]){
                ans[j]++;
            }
        }
    }
    //
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}

