#include<bits/stdc++.h>
using namespace std;
//#define mid n/2
long long n,a[200006],len=0,b[200006],ans=0;
char c[200006];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld%c%c",&a[i],&c[i],&c[i]);
        b[i]=len+1;
        len+=a[i];
    }
    /*for(int i=1;i<=n;i++)
    {
        printf("%lld %lld  ",b[i],a[i]);
    }
    printf("\n");*/
    long long l=0,li=1,ri=n;
    while(1)
    {
        if(li>=ri) break;
        if(c[li]==c[ri])
        {
            if(b[li]+a[li]-1>len-b[ri]+1)
            {
                l=len-b[ri]+1;
                ri--;
            }
            else if(b[li]+a[li]-1==len-b[ri]+1)
            {
                l=len-b[ri]+1;
                ri--;
                li++;
            }
            else if(b[li]+a[li]-1<len-b[ri]+1)
            {
                l=b[li]+a[li]-1;
                li++;
            }
        }
        else
        {
            if(b[li]+a[li]-1>len-b[ri]+1)
            {
                ans+=(len-b[ri]+1)-l;
                l=len-b[ri]+1;
                ri--;
                //cout<<"111"<<" ";
            }
            else if(b[li]+a[li]-1==len-b[ri]+1)
            {
                ans+=(len-b[ri]+1)-l;
                l=len-b[ri]+1;
                ri--;
                li++;
            }
            else if(b[li]+a[li]-1<len-b[ri]+1)
            {
                ans+=(b[li]+a[li]-1)-l;
                l=b[li]+a[li]-1;
                li++;
            }
        }
        //cout<<li<<" "<<ri<<" "<<ans<<" "<<l<<"\n";
    }
    printf("%lld",ans);
    return 0;
}
