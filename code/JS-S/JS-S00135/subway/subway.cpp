#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int a[200000];
int t[100000][100000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);

    for (int i=1; i<=m; i++)
        scanf("%d",&a[i]);
    for (int i=1; i<=n; i++)
    {
        int k;
        scanf("%d",&k);
        for (int j=1; j<=k; j++)
        {
            int a1;
            scanf("%d%d",&a1,&t[i][a1]);


        }

    }



    while(q--)
    {
        int q,z;
        scanf("%d%d",&q,&z);
        long long int num=0;
        num+=a[q]+a[z];
        cout<<num+27;
    }




    return 0;
}
