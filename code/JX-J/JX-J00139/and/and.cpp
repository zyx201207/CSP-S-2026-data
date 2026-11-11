#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000],ma;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    if(m==1){
        for(int i=1;i<=n;i++)
            ma=max(ma,a[i]);
        printf("%d",ma);
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;i+j<=n;j++)
                ma=max(ma,a[i]&a[j+i]);
        printf("%d",ma);
        return 0;
    }
    sort(a+1,a+n+1);
    printf("%d",a[n-m]);
    return 0;
}

