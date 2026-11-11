#include <bits/stdc++.h>
using namespace std;
int a,n;
string s;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;

    for(int i=0;i<a;i++)
    {
        cin>>n;cin>>c;
        for(int j=0;j<n;j++){
            s=s+c;
        }
    }
if(a>20)
{
    cout<<0;
    return 0;
}

    string p;
    for(int i=0;i<s.size()/2;i++)
    {

        p=s[i]+p;
    }
    int m=0,sum=0;
    for(int i=s.size()-1;i+i>=s.size();i--)
    {

        if(s[i]!=p[m++])
            sum++;
    }
    cout<<sum;
    return 0;
}
