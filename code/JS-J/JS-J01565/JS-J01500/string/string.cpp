#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ss{
    int a;
    char b;
};
int n=0,cnt1=0,cnt2=0,cnt3=0,num1=1,num2=0,ans=0;
char c;
ss s[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    num2=n;
    for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b;
    while(num1<=num2)
    {
        cnt1+=s[num1].a;
        c=s[num1].b;
        while(cnt2<=cnt1)
        {
            cnt2+=s[num2].a;
            if(cnt2>cnt1)
            {
                if(s[num2].b!=c) ans=ans+cnt1-cnt2+s[num2].a;
                cnt3=cnt1-cnt2+s[num2].a;
                cnt2=cnt1;
                break;
            }
            else
            {
                if(s[num2].b!=c && cnt3!=0)
                {
                    ans+=s[num2].a-cnt3;
                    cnt3=0;
                }
                else if(s[num2].b!=c)
                {
                    ans+=s[num2].a;
                }
                num2--;
            }
        }
        num1++;
    }
    cout<<ans;
    return 0;
}
