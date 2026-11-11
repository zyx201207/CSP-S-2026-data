#include<bits/stdc++.h>
using namespace std;
int a[500010];
int last[500010];
int p[500010];
int ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int top=0;
        for(int j=1;j<=m;j++)  last[j]=0;
        for(int l=i;l<=n;l++){
            if(last[a[l]]!=0){
                top=last[a[l]];
                for(int k=last[a[l]]+1;k<=top;k++)  last[p[k]]=0;
            }else{
                p[++top]=a[l];
                last[a[l]]=top;
            }
        }
        for(int j=1;j<=top;j++)  ans[p[j]]++;
        for(int j=top;j>=1;j--)  p[top--]=0;
    }
    for(int i=1;i<=m;i++)  printf("%d ",ans[i]);
    return 0;
}
