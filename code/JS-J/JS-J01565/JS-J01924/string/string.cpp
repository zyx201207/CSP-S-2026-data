#include<bits/stdc++.h>
using namespace std;
long long a[200005], ans;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i];
    }
    int i = 1, j = n;
    while(i <= j)
    {
        if(a[i]>a[j])
        {
            if(b[i] != b[j])
            {
                ans+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
        else if(a[i] == a[j])
        {
            if(b[i] != b[j])
            {
                ans+=a[j];
            }
            i++;
            j--;
        }
        else
        {
            if(b[i] != b[j])
            {
                ans+=a[i];
            }
            a[j]-=a[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}
