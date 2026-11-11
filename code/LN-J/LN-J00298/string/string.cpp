#include<bits/stdc++.h>
using namespace std;
int huiwen(string l,string r1)
{
    int jsq=0;
    string r;
    for(int i=0;i<l.size();i++)
    {
        r[i]=r1[l.size()-i-1];
    }
    for(int i=0;i<l.size();i++)
    {
        if(l[i]!=r[i])
        {
            jsq++;
        }
    }
    return jsq;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,shu;
    char zi;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>shu>>zi;
        for(int i=0;i<shu;i++)
        {
            a+=zi;
        }
    }
    if(a.size()%2==1)
    {
        cout<<huiwen(a.substr(0,a.size()/2),a.substr(a.size()/2+1,a.size()/2));
    }
    else
    {
        cout<<huiwen(a.substr(0,a.size()/2),a.substr(a.size()/2,a.size()/2));
    }
    return 0;
}
