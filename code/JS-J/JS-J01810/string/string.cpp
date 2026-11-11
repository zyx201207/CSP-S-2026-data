#include<bits/stdc++.h>
using namespace std;
long long n,a[210000];
char ac[210000];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //scanf("%d",&n);
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        /*scanf("%d",&ta);
        scanf("%c",&tac);
        a[i] = ta;
        ac[i] = tac;*/
        cin>>a[i]>>ac[i];
        for(int j = 0;j < a[i];j++)
        {
            s += ac[i];
        }
    }
    long long c = 0LL;
    for(int i = 0;i < s.size()/2;i++)
    {
        if(s[i] != s[s.size()-i-1]) c++;
    }
    cout<<c<<endl;
    return 0;
}
