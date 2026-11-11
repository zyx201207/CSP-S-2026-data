#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum+=a[i];
    long long cost=0,i=1,j=n,l=0,r=sum,pre1=0,pre2=0;
    while(i<j&&l<=r)
    {
        long long cur=min(pre1+a[i]-l,pre2+a[j]-(sum-r));
        if(c[i]!=c[j])cost+=cur;
        if(pre1+a[i]-l==cur)pre1+=a[i++];
        if(pre2+a[j]-(sum-r)==cur)pre2+=a[j--];
        l+=cur,r-=cur;
    }
    cout<<cost;
    return 0;
}
