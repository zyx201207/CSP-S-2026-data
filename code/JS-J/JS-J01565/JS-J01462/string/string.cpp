#include <bits/stdc++.h>
using namespace std;
long long n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<long long> a(n);
    vector<char> c(n);
    for(long long i=0;i<n;i++) {
        cin>>a[i]>>c[i];
    }
    unsigned long long ans=0,sum;
    long long l=0,r=n-1;
    while(l<r){
        sum=min(a[l],a[r]);
        if(c[l]!=c[r])ans+=sum;
        a[l]-=sum,a[r]-=sum;
        if(a[l]==0) l++;
        else r--;
    }
    cout<<ans<<'\n';
    return 0;
}
