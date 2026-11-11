#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
size_t l,l2,t=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %c",&a,&c);
        for(int j=0;j<a;++j) s+=c;
    }
    l=s.size();
    l2=l>>1;
    for(size_t i=0;i<l2;++i)
    {
        if(s[i]!=s[l-i-1]) ++t;
    }
    cout<<t;
    return 0;
}
