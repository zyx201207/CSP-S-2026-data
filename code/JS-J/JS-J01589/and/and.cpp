#include <bits/stdc++.h>
using namespace std;

struct bin
{
    bool bit[35]={};
    int h=0;
}b[200005];
void toBin(int x,int n,int p)
{
    if (x==0)
    {
        b[n].h = p-1;
        return;
    }
    b[n].bit[p] = x%2;
    toBin(x/2,n,p+1);
    return;
}
bool cmp(bin a,bin b)
{
    return a.h>b.h;
}
/*void and(bin x,bin y,bin &z)
{
    for (int i=0;i<=min(x.h,y.h);i++)
    {
        z.bit[i] = x.bit[i]&&y.bit[i];
    }
    return;
}*/
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        toBin(a,i,0);
    }
    sort(b+1,b+n+1,cmp);
    int temp=b[1].h;
    bin res;
    memset(res.bit,1,b[1].h+1);
    bool f=0,t_b=1;
    for (int i=b[1].h;i>=0;i--)
    {
        for (int j=1;j<=n;j++)
        {
            if (m==0)
            {
                f = 1;
                break;
            }/*
            if (b[j].h==b[j+1].h&&t_b)
            {
                t_b = 0;
                //and(b[j],b[j+1],res);
                for (int k=0;k<=temp;k++)
                {
                    res.bit[i] = b[j].bit[i]&&b[j+1].bit[i];
                }
                j++;
                m -= 2;
                break;
            }
            else*/ if (b[j].h==temp)
            {
                for (int k=0;k<=temp;k++)
                {
                    res.bit[k] = b[j].bit[k]&&res.bit[k];
                }
                m--;
                break;
            }
        }
        if (f)
        {
            break;
        }
        temp--;
    }
    long long sum=0;
    for (int i=0;i<32;i++)
    {
        sum += res.bit[i]*pow(2,i);
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
