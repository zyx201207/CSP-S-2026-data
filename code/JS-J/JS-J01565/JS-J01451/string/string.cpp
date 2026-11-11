#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N];
char c[N];
int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin>>n;
    long long s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    long long l=1,r=n,xl=0,xr=0,ans=0;
    while(l<r){
        if(a[l]<a[r]){
            xr+=a[r];
            while(xl+a[l]<xr){
                xl+=a[l];
                if(c[l]!=c[r])ans+=a[l];
                l++;
            }
            if(c[l]!=c[r])ans+=xr-xl;
            a[l]-=(xr-xl);
            r--;
            xl=xr;
        }
        else{
            xl+=a[l];
            while(xr+a[r]<xl ){
                xr +=a[r];
                if(c[l ]!=c[r ])ans+=a[r ];
                r--;
            }
            if(c[l]!=c[r])ans+=xl-xr;
            a[r ]-=(xl -xr);
            l++;
            xr=xl;
        }
    //    cout<<ans<<"\n";
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
