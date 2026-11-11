#include<bits/stdc++.h>
using namespace std;
int a,b=0,d,e;
char c[a],p[10010010];
int s[a];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    for(int i=0;i<a;i++)
    {
        cin>>s[i]>>c[i];
        d+=s[i];
        for(int j=0;j<s[i];j++)
        {
            p[b]=c[i];
            b++;
        }
    }  
    for(int j=0;j<p.size();j++)
    {
        if(p[j]!=p[d-1])
        {
            e++;
            d--;
        }
        else
        {
            d--;
        }
    }   
    cout<<e;
    return 0;
}