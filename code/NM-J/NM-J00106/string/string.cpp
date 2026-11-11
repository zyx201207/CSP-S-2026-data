#include<bits/stdc++.h>
using namespace std;
int n;
long long l;
int a[1000056];
char c[1000056];
long long s[1000056];
long long maxn=-1;
long long ans=0;
bool cmp(int a,int b)
{
    return a>b;
}
struct
{
    int number;
    char o;
    int ff;
}aa[1000056];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    memset(s,-1,sizeof(s));
    cin>>n;
    int k=0;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l+=a[i];
        if(f==0)
        {
            k++;
            s[k]=0;
            s[k]+=a[i];
            f=1;
            aa[k].number=a[i];
            aa[k].o=c[i];
            aa[k].ff=0;
        }
        while(f==1)
        {
            i++;
            if(c[i]==c[i-1])
            {
                s[k]+=a[i];
                aa[k].number+=a[i];
            }
            else
            {
                f=0;
                i--;
            }
        }
    }
    int pp=0;
    sort(s+1,s+n+1,cmp);
    maxn=s[1];
    if(maxn>=(l+1)/2)
    {
        cout<<l-maxn;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=-1)
        {
            sum++;
        }
    }
    for(int i=2;i<=n;i++)
    {
        ans+=s[i];
        int p=0;
        while(p<=s[i] && i<=n)
        {
            i++;
            p+=s[i];
        }
        if(i==n && p<=s[i])
        {
            break;
        }
        i--;
    }
    cout<<ans;
    return 0;
}
