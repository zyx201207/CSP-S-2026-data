#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,f=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            t[a[j]]++;
            for(int k=j-1;k>=i;k--){
                if(a[k]==a[j]){
                    f=1;
                    break;
                }
            }
            if(f==1){
                f=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(b[a[i]]==0){
            printf("%d %d\n",t[a[i]],a[i]);
            b[a[i]]=1;
        }
    }
    return 0;
}
