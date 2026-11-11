#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct str{
    ll le;
    char name;
}aaa[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>aaa[i].le>>aaa[i].name;
    }
    int i=1;
    int j=n;
    while(i<j)
    {
        if(aaa[i].le>aaa[j].le)
        {
            if(aaa[i].name!=aaa[j].name)
            {
                ans+=aaa[j].le;
            }
            aaa[i].le-=aaa[j].le;
            j--;
        }
        else if(aaa[i].le==aaa[j].le)
        {
            if(aaa[i].name!=aaa[j].name)
            {
                ans+=aaa[j].le;
            }
            i++;
            j--;
        }
        else
        {
            if(aaa[i].name!=aaa[j].name)
            {
                ans+=aaa[i].le;
            }
            aaa[j].le-=aaa[i].le;
            i++;
        }
    }
    cout<<ans;
    return 0;
}

