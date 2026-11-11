#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0,sum=0;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++)
        {
            s+=c;
        }
        l+=x;
    }
    int last=s[0],f=1;
    for(int i=1;i<l;i++)
    {
        if(s[i]!=last)f=0;
    }
    if(f)
    {
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    string a="",b="";
    for(int i=0;i<=l/2-1;i++)
    {
        a[i]+=s[i];
    }
    for(int i=0;i<=l/2-1;i++)
    {
        b[i]+=s[l-i-1];
    }
    for(int i=0;i<=l/2-1;i++)
    {
        if(b[i]!=a[i])sum++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
