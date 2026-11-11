#include <bits/stdc++.h>
using namespace std;

int n,m,a[500002],x[500002],top;
long long ans[500002];
bool f[500002];
int p[500002];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[j]=false;
        }
        top=0;
        for(int j=i;j<=n;j++){
            top++;
            x[top]=a[j];
            if(f[a[j]]==true){
                for(int k=p[a[j]]+1;k<top;k++){
                    f[x[k]]=false;
                }
                top=p[a[j]];
            }
            else {
                f[a[j]]=true;
                p[a[j]]=top;
            }
        }
        for(int i=1;i<=top;i++){
            ans[x[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}

