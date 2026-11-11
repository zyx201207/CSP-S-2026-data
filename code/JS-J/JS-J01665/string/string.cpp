#include<bits/stdc++.h>
using namespace std;

struct str{
    int a;
    char c;
}s[200001];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    int i=0,j=n-1;
    long long x=0;
    while(i<j)
    {
        if(s[i].a<s[j].a)
        {
            if(s[i].c!=s[j].c)
            {
                x+=s[i].a;
            }
            s[j].a-=s[i].a;
            i++;
        }else
        {
            if(s[i].c!=s[j].c)
            {
                x+=s[j].a;
            }
            s[i].a-=s[j].a;
            j--;
        }
    }
    cout<<x;
    return 0;
}
