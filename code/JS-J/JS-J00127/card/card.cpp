#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[300010], top;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        top = 0;
        for(int j=i; j<=n; j++)
        {
            int pos = top, k = a[j];
            while(b[pos] != k && pos >= 1)
                pos--;
            if(pos)
                top = pos;
            else
                b[++top] = k;
        }
        for(int i=1; i<=top; i++)
            c[b[i]]++;
    }
    for(int i=1; i<=m; i++)
        printf("%d ",c[i]);
    return 0;
}
