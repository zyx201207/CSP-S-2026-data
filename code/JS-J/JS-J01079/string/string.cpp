#include<bits/stdc++.h>
using namespace std;
int a,b[200005],l[200005],g=1;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b[i]>>c;
        l[i]=int(c);
    }
    for(int i=0;i<a-1;i++)
    {
        if(l[i]==l[i+1]);
        g++;
    }
    if(g==a)
    {
        cout<<0;
        return 0;
    }
    if(a==1)
    {
        cout<<0;
        return 0;
    }
    if(a==2)
    {
        if(l[0]=l[1])
            cout<<0;
        else
            cout<<max(b[0],b[1]);
            return 0;
    }
    return 0;
}
