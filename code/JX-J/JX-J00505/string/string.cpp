#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long sum;
struct
{
    int num;
    char zifu;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].num >> a[i].zifu;
        sum += a[i].num;
    }
    int i =1,j = sum;
    int xx = 1;
    int yy = n;
    long long numx = a[1].num;
    long long numy = a[n].num;
    for (; ; )
    {
        char x=a[xx].zifu,y=a[yy].zifu;
        if (numx-- < 0 )
        {
            numx = a[++xx].num;
        }
        if (numy-- < 0 )
        {
            numy = a[--yy].num;
        }
        numx--;
        numy--;

        if (x != y)
        {
            ans++;
        }
        if (i+1 == j || i ==j)
        {
            break;
        }
        i++;
        j--;
    }
    cout << max(0LL,ans-1)<<'\n';
    return 0;
}






