#include<bits/stdc++.h>
using namespace std;
string s,c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0,len=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        s+=c;
        len+=a;
    }

    int l=len;
    for(int i=1;i<=len/2+1;i++)
    {

        if(s[i]==s[l])
        {
            continue;
        }
        else
        {
            cnt++;
        }
        l--;
    }
    cout<<cnt;
    return 0;
}

