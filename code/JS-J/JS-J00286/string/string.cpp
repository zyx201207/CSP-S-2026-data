#include<bits/stdc++.h>
using namespace std;

struct V
{
    long long g;
    char c;
}a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].g >> a[i].c;
        sum+=a[i].g;
    }
    int k=0;
    long long s=0,m=0;
    for (int i=1;i<=n;i++)
    {
        s+=a[i].g;
        if (s>=sum/2)
        {
            k=i;
            m=sum/2-(s-a[i].g);
            break;
        }
    }
    long long cnt=0;
    int l=1,r=n;
    while (l<=k && r>=k)
    {
        if (a[l].c==a[r].c)
        {
            if (a[l].g<a[r].g)
            {
                cnt+=a[l].g;
                a[r].g=a[r].g-a[l].g;
                l++;
                continue;
            }
            else if (a[l].g>a[r].g)
            {
                cnt+=a[r].g;
                a[l].g=a[l].g-a[r].g;
                r--;
                continue;
            }
            else cnt+=a[l].g;
        }
        l++;
        r--;
    }
    cnt+=min(m,a[k].g-m);
    cout << sum/2-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
