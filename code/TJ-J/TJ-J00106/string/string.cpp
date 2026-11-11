#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    long long left=1,lnow=a[1],right=n,rnow=a[n];
    while(left<right)
    {
        if(lnow==0)
        {
            left++;
            lnow=a[left];
            continue;
        }
        if(rnow==0)
        {
            right--;
            rnow=a[right];
            continue;
        }
        if(c[left]==c[right])
        {
            if(lnow>=rnow)
            {
                lnow-=rnow;
                right--;
                rnow=a[right];
                continue;
            }
            else
            {
                rnow-=lnow;
                left++;
                lnow=a[left];
                continue;
            }
        }
        else{
                if(lnow>=rnow)
            {
                lnow-=rnow;
                cnt+=rnow;
                right--;
                rnow=a[right];
                continue;
            }
            else
            {
                rnow-=lnow;
                cnt+=lnow;
                left++;
                lnow=a[left];
                continue;
            }
        }
    }
    cout << cnt;
    return 0;
}
