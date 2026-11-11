#include<bits/stdc++.h>
using namespace std;
struct use
{
    long long many;
    char is;
}a[10000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].many>>a[i].is;
    }
    int j=n;
    for(int i=1;i<j;)
    {
        if(a[i].is!=a[j].is)
        {
            if(a[i].many==a[j].many)
            {
                sum+=a[i].many;
                i++;
                j--;
            }
            else if(a[i].many>a[j].many)
            {
                a[i].many-=a[j].many;
                j--;
                sum+=a[j].many;
            }
            else if(a[i].many<a[j].many)
            {
                i++;
                a[j].many-=a[i].many;
                sum+=a[i].many;
            }
        }
       else if(a[i].is==a[j].is)
       {
            if(a[i].many==a[j].many)
            {
                i++;
                j--;
            }
            else if(a[i].many>a[j].many)
            {
                a[i].many-=a[j].many;
                j--;
            }
            else if(a[i].many<a[j].many)
            {
                i++;
                a[j].many-=a[i].many;
            }
       }
    }
    cout<<sum;
    return 0;
}
