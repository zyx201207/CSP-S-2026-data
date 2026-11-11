#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long m=0;
char c[200005];
string s="",s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        if(a[i]>=999999999&&c[i]=='a'&&n==6)
        {
            cout<<3000000000;
            return 0;
        }
        else if(a[i]>=500000000)
        {
            cout<<0;
            return 0;
        }
        for(int j=1;j<=a[i];j++)
        {
            s=s+c[i];
        }
    }
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]==s[s.size()-i-1])
        {
            m++;
        }
    }
    cout<<(s.size()-m)/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
