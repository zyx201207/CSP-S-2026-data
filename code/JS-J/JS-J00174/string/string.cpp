#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
char c[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    long long len=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    long long half=len/2,len1=0,len2=0,pos1=1,pos2=n,ans=0;
    while(len1<half&&len2<half)
    {
        if(a[pos1]==a[pos2]&&c[pos1]==c[pos2]) len1+=a[pos1++],len2+=a[pos2--];
        else if(a[pos1]==a[pos2]&&c[pos1]!=c[pos2]&&len1+a[pos1]<=half) len1+=a[pos1],len2+=a[pos2--],ans+=a[pos1],pos1++;
        else if(a[pos1]==a[pos2]&&c[pos1]!=c[pos2]) ans+=a[pos1]-half,len1+=a[pos1++];
        else if(c[pos1]!=c[pos2])
        {
            if(a[pos1]<a[pos2])
            {
                if(len1+a[pos1]>half) ans+=a[pos1]-half,len1+=a[pos1];
                else len1+=a[pos1],a[pos2]-=a[pos1],len2+=a[pos1],ans+=a[pos1],pos1++;
            }
            else if(a[pos1]>a[pos2])
            {
                if(len1+a[pos2]>half) ans+=a[pos2]-half,len1+=a[pos2];
                else len1+=a[pos2],a[pos1]-=a[pos2],len2+=a[pos2],ans+=a[pos2],pos2--;
            }
        }
        else
        {
             if(a[pos1]<a[pos2]) len1+=a[pos1],a[pos2]-=a[pos1],len2+=a[pos1],pos1++;
             else if(a[pos1]>a[pos2]) len1+=a[pos2],a[pos1]-=a[pos2],len2+=a[pos2],pos2--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
