#include<bits/stdc++.h>
using namespace std;
long long sl[200005];
char zf[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,s=0;
cin>>n;
long long l=0,r=n-1;
for(int i=0;i<n;i++)
{
cin>>sl[i]>>zf[i];
}
while(l<=r)
{
long long  minn=min(sl[l],sl[r]),k;
if(sl[l]>=sl[r])
k=1;
else
k=0;
if(zf[l]!=zf[r])
{
    s+=minn;
    if(k)
    {
        r--;
        sl[l]-=minn;
    }
    else
    {
        l++;
        sl[r]-=minn;
    }
}
else{
      if(k)
    {
        r--;
        sl[l]-=minn;
    }
    else
    {
        l++;
        sl[r]-=minn;
    }
}
if(sl[l]==0)
{
    l++;
}
if(sl[r]==0)
{
    r--;
}
}
cout<<s;
return 0;
}
