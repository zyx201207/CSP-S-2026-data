#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n,a[200002];
    char b[200002];
   // cout<<"n"<<":";
    scanf("%d",&n);
    //cin>>n;
    for(int i=1;i<=n;i++)
    {
    //   cout<<"a"<<i<<":";
      //  cin>>a[i];
        scanf("%d %c",&a[i],&b[i]);
       // cout<<"b"<<i<<":";
      //  scanf("%c ",&b[i]);
    }
    int l=1,r=n;
    long long int s=0;
    int ls=a[1],rs=a[n];
    while(l<r)
    {
        //
        if(ls<rs)
        {
            if(b[l]!=b[r]) s+=ls;
            rs-=ls;
            l++;
            ls=a[l];
        }
        else if(ls>rs)
        {
            if(b[l]!=b[r]) s+=rs;
            ls-=rs;
            r--;
            rs=a[r];
        }
        else
        {
            if(b[l]!=b[r]) s+=ls;
            //ls-=rs;
            l++;
            ls=a[l];
            r--;
            rs=a[r];
        }
    }
    printf("%lld\n",s);
    return 0;
}
