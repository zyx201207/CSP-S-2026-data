#include<bits/stdc++.h>
using namespace std;
int a=100000000;
char c=10000;
int main()
    {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    string s,s2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    x=s.size();
    for(int i=x;i>=1;i--)
    {
        s2+=s;
    }
    if(s2==s2)
        cout<<'0';
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
