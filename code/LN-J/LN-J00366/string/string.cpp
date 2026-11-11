#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        for(long long i=0;i<a;i++)
        {
            s+=c;
            l++;
        }
    }
    if(l%2==0)
    {
        for(long long i=0;i<=l/2-1;i++)
        {
            if(s[i]!=s[l-1-i])
            {
                 sum++;
            }
        }
    }
    else
    {
        for(long long i=0;i<=l/2;i++)
        {
            if(s[i]!=s[l-1-i])
            {
                 sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
