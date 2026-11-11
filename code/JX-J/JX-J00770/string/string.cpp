#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    char x;
}t[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0;
    long long sum=0;
    long long ans=0;
    int cnt;
    cin>>n;
    string s1;
    string s2;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].x;
        //ta[i].a=t[i].a;
       // ta[i].x=t[i].x;
        l+=t[i].a;
    }
    for(int i=1;i<=n;i++)
    {
        sum+=t[i].a;
        if(sum>=l/2)
        {
            cnt=i;
            break;
        }
    }
    int ss=0;
    for(int i=1;i<=cnt;i++)
    {
        while(t[i].a)
        {
            s1[ss]=t[i].x;
            ss++;
            t[i].a=t[i].a-1;
            if(ss>=l)break;
        }
    }
    int sss=0;
    for(int i=cnt+1;i<=n;i++)
    {
        while(t[i].a)
        {
            s2[sss]=t[i].x;
            sss++;
            t[i].a=t[i].a-1;
        }
    }
    reverse(s2.begin(),s2.end());
    for(int i=0;i<l/2;i++)
    {
        if(s1[i]!=s2[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
