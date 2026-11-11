#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans=1,cnt=0;
long long pre[200010];
string s=" ";
int check(int s)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(s>pre[mid])l=mid+1;
        else r=mid;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        cin>>c[i];
        ans+=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(long long i=1;i<=(ans+1)/2;i++)
    {
        int ccnt=check(i);
        int cnnt=check(ans-i);
        if(c[ccnt]!=c[cnnt])cnt++;
    }
    cout<<cnt;
}
