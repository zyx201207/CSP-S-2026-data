#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[1000001],c[1011];
long long ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        b[a[i]]++;
        if(b[a[i]]==2)
            for(int j=c[a[i]];j<i;j++)
                b[a[j]]--;
        c[a[i]]=i;

    }
    for(int i=1;i<=m;i++)
        printf("%d ",b[a[i]]);
}
