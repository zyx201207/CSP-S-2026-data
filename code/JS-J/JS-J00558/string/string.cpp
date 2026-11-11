#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
int n,a[maxn],l,r;
char c[maxn];
long long sum,suml,sumr,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
    l=1,r=n,suml=0,sumr=sum+1;
    while(l<r)
    {
        // cout<<a[l]<<" "<<a[r]<<" "<<c[l]<<" "<<c[r]<<'\n';
        if(a[l]<=a[r])
        {
            if(suml+a[l]<=sum/2&&sumr-a[l]>(sum+1)/2)
            {
                suml+=a[l];sumr-=a[l];
                if(c[l]!=c[r]) ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
        else
        {
            if(suml+a[r]<=sum/2&&sumr-a[r]>(sum+1)/2)
            {
                suml+=a[r];sumr-=a[r];
                if(c[l]!=c[r]) ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/