#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int p[30];
int main()
{

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n,cnt=0,x=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        cnt+=a[i];
        cin>>c[i];
        p[c[i]]++;
        if(p[c[i]]==n)
        {
            cout<<0;
            return 0;
        }
    }


    for(int i=1; i<=(n+1)/2; i++)
    {

        if(a[i] == a[n+1-i])
        {
            if(c[i] == c[n+1-i])
            {
                if(i!=(n+1)/2)
                    x+=2*a[i];
                else if(i==(n+1)/2)
                    x+=a[i];
            }

            else if(c[i] != c[n+1-i])
                x+=a[i];
        }
        else
        {
            if(a[i]>a[n+1-i])
            {
                x+=a[i];
                a[n-i]-=a[i]-a[n+1-i];
            }
            else if(a[i]<a[n+1-i])
            {
                x+=a[n+1-i];
                a[i+1]-=a[n+1-i]-a[i];
            }


        }
    }

    cout<<cnt-x;
    return 0;

}
