#include <bits/stdc++.h>
using namespace std;
int n,m,a[200000],cards[200000],c,b[100001],ans[200000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=m;i++)b[i]=-1;
    for(int i=0;i<n;i++){
        c=0;
        for(int j=i;j<n;j++){
            if(b[a[j]]!=-1&&b[a[j]]<c&&cards[b[a[j]]]==a[j]){
                c=b[a[j]];
            }
            cards[c]=a[j];
            b[a[j]]=c;
            c++;
        }
        for(int j=0;j<c;j++){
            ans[cards[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
