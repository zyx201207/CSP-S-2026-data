#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int long long a,num=0,q=1,p=0;
    string s;
    cin>>a;
    for(int long long i=1;i<=a;i++)
    {
        int long long b;
        string c;
        cin>>b>>c;
        num+=b;
        for(int j=1;j<=b;j++)
        {
            s+=c;
        }
    }
    num--;
    if(num%2==0)
    {
        q++;
        for(int long long i=num/2-1;i>=0;i--)
        {
            if(s[i]!=s[num/2-1+q])
            {
                p++;
            }
            q++;
        }
    }
    else{
        num--;
        for(int long long i=num/2;i>=0;i--)
        {
            if(s[i]!=s[num/2+q])
            {
                p++;
            }
            q++;
        }
    }
    cout<<p;
    return 0;
}
