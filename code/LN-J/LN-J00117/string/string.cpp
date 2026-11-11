#include<bits/stdc++.h>
using namespace std;
long long ans=0,cnt=0,len=0;
long long a[200005];
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        len+=a[i];
    }
    //cout<<len<<'\n';
    long long cnt=0;
    int leftls=0,leftrs=0;
    int nowla=0,nowra=n+1;
    char nowls,nowrs;
    while(cnt<len/2)
    {
        if(!leftls)
        {
            nowls=s[++nowla],leftls+=a[nowla];
        }
        if(!leftrs)
        {
            nowrs=s[--nowra],leftrs+=a[nowra];
        }
        if(nowls==nowrs)
        {
            if(leftls<leftrs)
            {
                cnt+=leftls;
                leftrs-=leftls,leftls=0;
            }
            if(leftls>leftrs)
            {
                cnt+=leftrs;
                leftls-=leftrs,leftrs=0;
            }
            if(leftls==leftrs)
            {
                cnt+=leftrs;
                leftls=leftrs=0;
            }
        }
        if(nowls!=nowrs)
        {
            if(leftls==leftrs)
            {
                ans+=leftls;
                cnt+=leftls;
                leftls=leftrs=0;
                continue;
            }
            if(leftls<leftrs)
            {
                cnt+=leftls;
                ans+=leftls;
                leftrs-=leftls,leftls=0;
            }
            if(leftls>leftrs)
            {
                cnt+=leftrs;
                ans+=leftrs;
                leftls-=leftrs,leftrs=0;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}