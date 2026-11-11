#include <bits/stdc++.h>
using namespace std;
string a[200005];
int cnt[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=1,flag=0,h=0;
    cin>>n;
    string s,sq;
    for(int i=1;i<=n;i++)
    {
        cin>>cnt[i];
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt[i];j++)
            s=s+a[i];
    }
    for(int i=s.size();i>=0;i--)
    {
        a[num]=s[i];
        num++;

    }
    for(int i=1;i<=num;i++)
    {
        sq=sq+a[i];
    }
    cout<<s<<endl;
    cout<<sq<<endl;
    for(int i=0;i<=s.size();i++)
    {
        if(sq[i+1]!=s[i])
        {
            flag=1;
            h++;
        }

    }
    if(flag==0)
    {

        cout<<0;
    }
    else{
        cout<<h/2;
    }







    return 0;
}
