#include<bits/stdc++.h>
using namespace std;
long long n,l,cnt,sp=0;
long long a[100005],oa[100005];
char c[100005],oc[1000005];
string s;

int main()

{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l+=a[i];

        if(c[i-1]==c[i])
        {
            sp++;
        }

    }

    if(sp==n-1)
    {

        cout<<0;
        return 0;
    }
    for(int i=n;i>=1;i--)
    {

        oa[n-i+1]=a[i];
        oc[n-i+1]=c[i];
    }
    for(long long i=1;i<=n;i++)
    {

        if(a[i]==oa[i] && c[i]!=oc[i])
        {

            cnt+=a[i];
        }
        if(oc[i]==c[i] && a[i]!=oa[i])
        {

            cnt=cnt+abs(a[i]-oa[i]);
        }
        if(a[i]!=oa[i] && oc[i]!=c[i])
        {

            cnt=cnt+max(a[i],oa[i]);
        }
    }


    cout<<cnt/2;
    return 0;
}

