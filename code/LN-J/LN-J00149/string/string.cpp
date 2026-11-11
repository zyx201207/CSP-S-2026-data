#include <bits/stdc++.h>
using namespace std;
string s;
long long n,cnt=0;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    long long i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {
            cnt++;
            i++;
            j--;
        }
    }
    cout<<cnt;
    return 0;
}
