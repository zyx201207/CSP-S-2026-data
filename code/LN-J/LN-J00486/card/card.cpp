#include <bits/stdc++.h>
using namespace std;

int n,m,a[2999999],f[390999],s[499999],ans[499999],d[499999];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(d,0,sizeof(d));
        int top=0;
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                f[a[j]]++;
                d[++top]=a[j];
                s[a[j]]=top;
            }
            else{
                top=s[a[j]];
                s[a[j]]=top;
            }
        }
        for(int j=1;j<=top;j++)
            ans[d[j]]++;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}
