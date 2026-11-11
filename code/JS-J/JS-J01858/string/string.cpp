#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    long long l=1,r=n;
    while(l<=r){
        if(l==r)break;
        long long minx=min(a[l],a[r]);
        a[l]-=minx;
        a[r]-=minx;
        if(c[l]!=c[r])ans+=minx;
        if(a[l]==0)
            l++;
        if(a[r]==0)
            r--;
    }
    cout<<ans;
    return 0;
}
