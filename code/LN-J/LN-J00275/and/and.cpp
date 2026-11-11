#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int a[200005],s[200005],b[200005],c[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn = -1234567890,f=0,ans = 0,ms = -12345678890;
    cin >> n >> m;
    int d[m+5];
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        int y = a[i];
        maxn = max(maxn,a[i]);
        while(a[i]!=0)
        {
            s[f] = a[i] % 2;
            f++;
            a[i] = a[i] / 2;
        }
        for(int j = 0;j <= f-1;j++)
        {
            if(s[j] == 1)
            {
                ans++;
            }
        }
        b[y] = ans;
        c[y] = ans;
        f = 0;
        ans = 0;
    }
    sort(b,b+maxn+1,cmp);
    int z = 0;
    for(int i = 0;i < m;i++)
    {
        for(int j = 1;j <= maxn;j++)
        {
            if(b[i] == c[j])
            {
                d[z] = j;
                z++;
            }
            if(z == m)
            {
                break;
            }
        }
    }
    int num = d[0];
    for(int i = 1;i < z;i++)
    {
        num&=d[i];
    }
    cout << num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
