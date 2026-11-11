#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int sum[300005];
int sum1[300005];
int top=0;
int  cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]]>1)
        {
            while(top >0)
            {
                sum1[b[top]]=0;
                if (b[top] == a[i])
                {
                    top--;
                    break;
                }
                cnt[b[top]]--;
                top--;
            }

        }
        cnt[a[i]] = 1;
        b[++top] = a[i];
        sum1[a[i]]=1;
    }
    for (int i = 1;i <= m;i++)
    {
        sum[i] += sum1[i];
    }
    for (int j = 2;j <= n;j++)
    {
        for (int i = j;i <= n;i++)
        {
            cnt[a[i]]++;
            if (cnt[a[i]]>1)
            {
                while(top >0)
                {
                    sum1[b[top]]=0;
                    if (b[top] == a[i])
                    {

                        top--;
                        break;
                    }
                    cnt[b[top]]--;
                    top--;
                }

            }
            cnt[a[i]] = 1;
            b[++top] = a[i];
            sum1[a[i]]=1;
        }
        for (int k = 1;k <= m;k++)
        {
            sum[k] += sum1[k];
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << sum[i] <<" ";
    }
    cout <<'\n';
    return 0;
}








