#include<bits/stdc++.h>
using namespace std;
char c[200020];
int a[200020];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i]>>c[i];
    }
    int x=1,y=a[n];
    int i=1,j=n;
    while(i<=j)
    {

        if(c[i]!=c[j])
            ans++;
        x++;
        y--;
        if(x>a[i])
        {
            i++;
            x=0;
        }
        if(y==0)
        {
            j--;
            y=a[j];
        }
    }
    cout<<ans;
    return 0;
}
