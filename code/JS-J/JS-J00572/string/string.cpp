#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long n,a[N],ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(auto i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n,q=0;
    while(l<r){
        if(c[l]!=c[r])ans+=min(a[l],a[r]);
        a[l]=max(q,a[l]-a[r]);
        a[r]=max(q,a[r]-a[l]);
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<ans;
    return 0;
}
