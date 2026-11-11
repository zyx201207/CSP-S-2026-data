#include<bits/stdc++.h>
using namespace std;
struct xxpp{
    long long sum;char c;
}a[210000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0,cnt=0,max1,min1;
    string s1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].sum>>a[i].c;
        cnt+=a[i].sum;
    }
    long long l=1,r=n;
    while(l<r)
    {
        if(a[l].c!=a[r].c)
        {
            if(a[l].sum>a[r].sum)
            {
                ans+=a[r].sum;
                a[l].sum-=a[r].sum;
                r--;
            }
            else if(a[l].sum==a[r].sum)
            {
                ans+=a[r].sum;
                l++;r--;
            }
            else
            {
                ans+=a[l].sum;
                a[r].sum-=a[l].sum;
                l++;
            }
        }
        else
        {
            l++;r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
