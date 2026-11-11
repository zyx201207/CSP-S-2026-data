#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int a;
    string c;
}a[200005];
int n;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i].a >> a[i].c;
    int i=1,j=n;
    while(i<=j)
    {
        if(a[i].a==a[j].a&&a[i].c[0]==a[j].c[0])
            i++,j--;
        else
        {
            if(a[i].a==a[j].a)
                ans+=a[i].a,i++,j--;
            else if(a[i].c[0]==a[j].c[0])
                if(a[i].a>a[j].a)
                    a[i].a-=a[j].a,j--;
                else
                    a[j].a-=a[i].a,i++;
            else
            {
                ans+=min(a[i].a,a[j].a);
                if(a[i].a>a[j].a)
                    a[i].a-=a[j].a,j--;
                else
                    a[j].a-=a[i].a,i++;
            }
        }
    }
    cout << ans;
    return 0;
}
