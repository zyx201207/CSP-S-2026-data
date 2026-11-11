#include<bits/stdc++.h>
using namespace std;
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
typedef long long ll;
const int N=5e5+10;
int n,i,l,r,mid,ans;
ll m,a[N],sum[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scan>>n>>m;
    for (i=1;i<=n;i++) scan>>a[i];
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (i=1;i<=n;i++)
    {
        l=1;
        r=i;
        while (l<=r)
        {
            mid=l+r>>1;
            if (a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}