#include<bits/stdc++.h>
using namespace std;
long long n,num,np,nx;
long long a[200005],ans;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        num += a[i];
    }
    int i = 1,j = n;
    while(1)
    {
        bool flag = 1;
        for(int i=1;i<=n;i++)
        {
            if(a[i] != 0)
            {
                flag = 0;
            }
        }
        if(flag)
        {
            break;
        }
        if(b[i] == b[j])
        {
            if(a[i] > a[j])
            {
                a[i] -= a[j];
                a[j] = 0;
                j--;
            }
            else if(a[j] > a[i])
            {
                a[j] -= a[i];
                a[i] = 0;
                i++;
            }
            else
            {
                a[i] = 0;
                a[j] = 0;
                i++;
                j++;
            }
        }
        else{
            ans += min(a[i],a[j]);
            if(a[i] > a[j])
            {
                a[i] -= a[j];
                a[j] = 0;
                j--;
            }
            else if(a[j] > a[i])
            {
                a[j] -= a[i];
                a[i] = 0;
                i++;
            }
            else
            {
                a[i] = 0;
                a[j] = 0;
                i++;
                j++;
            }
        }
    }
    cout<<ans;
    return 0;
}
