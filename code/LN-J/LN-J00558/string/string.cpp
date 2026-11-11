#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,l,r,lsum,la[N],mid,sum=0,delta,ans=0;
long long a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out"."w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    mid=sum>>1;
    l=0,r=n+1;
    rsum=n;
    while(1)
    {
        if(lsum+a[l+1]<=mid){
            lsum+=a[l+1];
            l++;
        }
        else{
            if(rsum-a[r-1]>=mid){
                rsum-=a[r-1];
                r--;
            }
            else break;
        }
        cout<<r-1<<" "<<l<<" "<<r<<" "<<lsum<<" "<<rsum<<endl;
    }

    return 0;
}
