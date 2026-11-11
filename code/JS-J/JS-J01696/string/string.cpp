#include <bits/stdc++.h>
using namespace std;
int n,y,f=1,d=0,i,n1=0;
struct da{
    int a,b;
    char c;
}faa;
vector <da> a;
char x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>y>>x;
        n1+=y;
        faa.a=f;faa.b=f+y-1;faa.c=x;
        a.push_back(faa);
        f=faa.b+1;
    }
    while (!a.empty())
    {
        n=a.size()-1;
        if (a[0].c==a[n].c)
        {
            if (n1-a[n].a+1<a[0].b)
            {
                a[0].a=n1-a[n].b+2;
                a.pop_back();
            }
            else if (n1-a[n].a+1==a[0].b)
            {
                a.erase(a.begin());
                if (!a.empty())a.pop_back();
            }
            else
            {
                a[n].b=n1-a[0].a;
                a.erase(a.begin());
            }
        }
        else
        {
            if (n1-a[n].a+1<a[0].b)
            {
                d+=a[n].b-a[n].a+1;
                a[0].a=n1-a[n].b+2;
                a.pop_back();
            }
            else if (n1-a[n].a+1==a[0].b)
            {
                d+=a[n].b-a[n].a+1;
                a.erase(a.begin());
                if (!a.empty())a.pop_back();
            }
            else
            {
                d+=a[0].b-a[0].a+1;
                a[n].b=n1-a[0].a;
                a.erase(a.begin());
            }
        }
    }
    cout<<d;
    return 0;
}
