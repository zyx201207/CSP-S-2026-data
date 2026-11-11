#include<bits/stdc++.h>
using namespace std;
struct st
{
    long long l;
    char ch;
}s[200005];
long long n,ans;
string str;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].l>>s[i].ch;
        for(long long j=1;j<=s[i].l;j++)
            str+=s[i].ch;
    }
    long long len=str.length();
    for(int i=0;i<=n/2;i++)
        if(str[i]!=str[len-1-i])
        {
            str[len-1-i]=str[i];
            ans++;
        }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
