#include<bits/stdc++.h>
using namespace std;
int n;
long long ar[200005]={0};
long long i=0,j=0;
char ch[200005]={0};
long long temp=0;
long long cnt=0;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    temp=n;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i]>>ch[i];
    }
    for(i=1;i<=temp;i++)
    {

        if(ch[i]!=ch[temp])
        {
            if(ar[i]>ar[temp])
            {
                cnt+=ar[temp];
                ar[i]-=ar[temp];
                i--;
                temp--;
                continue;
            }
            else if(ar[i]<ar[temp])
            {
                cnt+=ar[i];
                ar[temp]-=ar[i];
                continue;
            }
            else
            {
                cnt+=ar[i];
                temp--;
                continue;
            }
        }
        else
        {
            if(ar[i]==ar[temp])
            {
                temp--;
                continue;
            }
            else if(ar[i]>ar[temp])
            {
                ar[i]-=ar[temp];
                i--;
                temp--;
                continue;
            }
            else
            {
                ar[temp]-=ar[i];
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}
