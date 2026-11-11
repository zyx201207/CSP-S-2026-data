#include<bits/stdc++.h>
using namespace std;
long long n;
long long i1;
long long cnt=0;
string a;
string b;
string c;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>i1;
        cin>>a;
        for(int i=1;i<=i1;i++)
        {
            b=b+a;
        }
    }
    for(int i=0;i<=b.size();i++)
    {

        if(a[i]!=b[i])
        {
            cnt++;

        }

    if(cnt<=b.size()&&cnt!=0)
    {
        bool n=0;
    }
    else if(cnt==0)
    {
        if(ans!=0)
            {
                if(b.size()%2==1)
                {
                    ans--;
                    cout<<ans;
                    return 0;
                }
            }
            else
            {
                cout<<ans;
                return 0;
            }
    }
        if(a[i]!=b[i])
            {
                a[i]=b[i];
                ans++;
            }
        }
    return 0;
}
