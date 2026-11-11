#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],s[500001],front=0,ans[500001];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        front=0;
        memset(b,0,sizeof(0));
        memset(s,0,sizeof(0));
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                front=b[a[j]];
                for(int k=1;k<front;k++)
                        b[a[k]]=0;
            }
            else
                s[++front]=a[j],b[a[j]]=front;
        }
        for(int j=1;j<=front;j++)
            ans[s[j]]++;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}
