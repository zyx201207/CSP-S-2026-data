#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
char k[200005];
long long a[200005];
stack<long long>a1,a2;
stack <char>s1,s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>k[i];
        s1.push(k[i]);
        a1.push(a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        s2.push(k[i]);
        a2.push(a[i]);
    }
    while(!s1.empty())
    {
        char p=s1.top(),q=s2.top();
        long long x=a1.top(),y=a2.top();
        if(p==q)
        {
            if(x>y)
            {
                a1.top()-=a2.top();
                a2.pop();
                s2.pop();
            }
            else if(x==y)
            {
                a1.pop();
                a2.pop();
                s1.pop();
                s2.pop();
            }
            else
            {
                a2.top()-=a1.top();
                a1.pop();
                s1.pop();
            }
        }
        else
        {
            cnt+=min(x,y);
            if(x>y)
            {
                a1.top()-=a2.top();
                s2.pop();
                a2.pop();
            }
            else if(x==y)
            {
                a1.pop();
                a2.pop();
                s1.pop();
                s2.pop();
            }
            else
            {
                a2.top()-=a1.top();
                a1.pop();
                s1.pop();
            }
        }
    }
    cout<<cnt/2;
    return 0;
}
