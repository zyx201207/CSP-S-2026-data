#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s=s+c;
        }
    }
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(i>=len-i-1)
        {
            cout<<cnt<<endl;
            return 0;
        }
        if(s[i]!=s[len-i-1]) cnt++;
    }
    return 0;
}
