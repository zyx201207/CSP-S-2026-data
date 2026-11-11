#include<bits/stdc++.h>
using namespace std;
int a[211111];
char c[211111];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    int i=0,j=n-1;
    long long ans=0;
    int x=a[0],y=a[n-1];
    while(1)
    {
        if(i==j || i>j)
            break;
        if(x<y)
        {
            if(c[i]!=c[j])
                ans+=x;
            y-=x;
            x=a[i+1];
            i++;
        }
        else if(x==y)
        {
            if(c[i]!=c[j])
                ans+=x;
            x=a[i+1];
            y=a[j-1];
            i++;
            j--;
        }
        else
        {
            if(c[i]!=c[j])
                ans+=y;
            x-=y;
            y=a[j-1];
            j--;
        }
    }
    cout<<ans;
    return 0;
}