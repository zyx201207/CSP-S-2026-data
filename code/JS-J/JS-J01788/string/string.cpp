#include<bits/stdc++.h>
using namespace std;
struct IAKIOI
{
    long long a;
    char c;
};
IAKIOI s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=1,r,k=1;
    long long sum=0,ans=0;
    cin>>n;
    char f1;
    for(int i=1;i<=n;i++)
    {
        long long x;
        char f;
        cin>>x>>f;
        if(i==1){f1=f;sum=x;continue;}
        if(f==f1) sum+=x;
        else{s[k].a=sum;s[k].c=f1;f1=f;sum=x;k++;}
    }
    s[k].a=sum;
    s[k].c=f1;
    n=k;
    r=n;
    while(l<r)
    {
        char c1=s[l].c,c2=s[r].c;
        long long ooo=min(s[l].a,s[r].a);
        s[l].a-=ooo;
        s[r].a-=ooo;
        if(s[l].a==0) l++;
        else r--;
        if(c1!=c2) ans+=ooo;
    }
    cout<<ans<<'\n';
    return 0;
}
