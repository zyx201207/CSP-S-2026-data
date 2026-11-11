#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
struct s{
    long long gs;char zm;
}a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].gs>>a[i].zm;
    l=1,r=n;
    while(l<r){
        if(a[l].gs<a[r].gs){
            a[r].gs-=a[l].gs;l++;
            if(a[l-1].zm!=a[r].zm)ans+=a[l-1].gs;
    }
        else if(a[r].gs<a[l].gs){
            a[l].gs-=a[r].gs;r--;
            if(a[l].zm!=a[r+1].zm)ans+=a[r+1].gs;
    }
        else {
            l++;r--;if(a[l-1].zm!=a[r+1].zm)ans+=a[l-1].gs;
        }
    }
    cout<<ans;
    return 0;
}
