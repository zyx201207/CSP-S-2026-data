#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int brr[100000];

int main ()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        if(n<4)
        {
            cout<<0;
            continue;
        }
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];

        }
        int x=arr[1]-arr[0];
        brr[0]=x;
        bool pd=true;
        for(int j=2;j<n;j++)
        {
            brr[j-1]=arr[j]-arr[j-1];
            if(arr[j]-arr[i]!=x)
            {
                pd=false;
            }
        }
        if(pd==true)
        {
            if(d%2!=0||d/x!=2)
            {
                cout<<0;
                continue;
            }
            cout<<n-3;
            continue;
        }
        int v=0,u=0;
        for(int j=1;j<n;j++)
        {
            u=u+arr[j]-arr[j-1];
            if(u>=d){
                v=j;
            }
            else{
                break;
            }
        }
        if(n-v<4)
        {
            cout<<0;
            continue;
        }


    }
    return 0;
}
