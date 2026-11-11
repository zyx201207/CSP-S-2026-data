#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long L;
 cin>>L;
    vector<string> a;
    vector<string> j;
    string S[L],TMD;
       long long f[L];
    for(long long i=0;i<L;i++)
    {
        cin>>f[i];
        cin>>S[i];
    }
    if(L==1)
    {
        cout<<"0";
    }
    for(long long i=0;i<L;i++)
    {
        for(long long d=0;d<f[i];d++)
        {
            a.push_back(S[i]);
        }
    }
    for(long long i=L;i>0;i--)
    {
        for(long long d=f[i];d>0;d--)
        {
            j.push_back(S[i]);
        }
    }
    if (a==j)
    {
        cout<<"0";
    }
    return 0;
}
