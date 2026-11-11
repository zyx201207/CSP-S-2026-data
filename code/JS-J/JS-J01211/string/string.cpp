#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n;
LL ans;
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;char ch;
        scanf("%d",&x);
        cin>>ch;
        for (int i=1;i<=x;i++)
        {
            s+=ch;
        }
    }
    for (LL i=0;i<=(s.size()-1)/2;i++)
    {
        if (s[i]!=s[s.size()-1-i])
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
