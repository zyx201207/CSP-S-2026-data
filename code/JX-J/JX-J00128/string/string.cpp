#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[200005]={0};
    char b[200005]="0";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        if((b[i]==b[i-1])&&(i>0))
        {
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    int c=0;
    int d;
    for(int i=0;i<(n/2);i++)
    {
        if(b[n-i-1]==b[i]&&(a[i]!=0))
        {
            if(a[n-i-1]!=a[i])
            {
                d=min(a[n-i-1],a[i]);
                a[n-i-1]-=d;
                a[i]-=d;
            }
        }else{
             d=min(a[n-i-1],a[i]);
                c+=d;
                a[n-i]-=d;
                a[i]-=d;
        }
    }
    cout<<c;
    return 0;
}

