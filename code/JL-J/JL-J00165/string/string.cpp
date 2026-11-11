#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,x1[N],x2[N],cnt1,cnt2,num1,num2,l1,l2,l,ans;
char c1[N],c2[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x1[i]>>c1[i];
        x2[n-i+1]=x1[i];
        c2[n-i+1]=c1[i];
        l+=x1[i];
    }
    while(l1<=l/2&&l2<=l/2)
    {
        if(!num1)
        {
            cnt1++;
            num1=x1[cnt1];
        }
        if(!num2)
        {
            cnt2++;
            num2=x2[cnt2];
        }
        int x=min(num1,num2);
        if(c1[cnt1]!=c2[cnt2])
            ans+=x;
        l1+=num1;
        l2+=num2;
        num1-=x;
        num2-=x;
        l1-=num1;
        l2-=num2;
    }
    cout<<ans<<endl;
    return 0;
}
