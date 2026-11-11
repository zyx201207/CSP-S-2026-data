#include<bits/stdc++.h>
using namespace std;
string b[200000000010001];
int s[27];
int main()
{
    freopen("string.in" ,"r" , "std.in");
    freopen("string.out" ,"w" , "std.out");
    long long n,x=1,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        string c;
        cin >> a >> c;
        if(c=="a")
        {
            s[1]=s[1]+a;
        }
        else if(c=="b")
        {
            s[2]=s[2]+a;
        }
        else if(c=="c")
        {
            s[3]=s[3]+a;
        }
        for(int j=x;j<=a+x;j++)
        {
            b[j]=c;
        }
        x=x+a;
    }
    for(int i=1;i<=x/2;i++)
    {
        if(b[i]!=b[x+1-i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
