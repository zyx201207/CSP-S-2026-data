#include<bits/stdc++.h>
using namespace std;
int n;
char c;
string s;
long long a,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        cin >> c;
        for(long long i=1;i<=a;i++)
        {
            s+=c;
        }
    }
    long long len=s.size();
    for(long long i=1;i<=len;i++)
    {
        if(s[i]!=s[len+1-i])
        {
            s[len+1-i]=s[i];
            cnt++;
        }
        else    continue;
    }
    cout << cnt;
    return 0;
}
