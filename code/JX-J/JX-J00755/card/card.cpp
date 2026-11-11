#include<bits/stdc++.h>
#define reg register
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int t[M];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    vector<int> a(n+1),b(n+1);
    for(reg int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(reg int i=1;i<=n;i++){
        for(reg int j=i;j<=n;j++)
            for(reg int k=i;k<j;k++)
                if(a[j]==a[k])
                    for(reg int s=k+1;s<=j;s++)
                        a[s]=0;
        for(reg int j=i;j<=n;j++)
            t[a[j]]++;
        for(reg int j=1;j<=n;j++)
            a[j]=b[j];
    }
    for(reg int i=1;i<=m;i++)
        printf("%d ",t[i]);
    printf("\n");
    return 0;
}
