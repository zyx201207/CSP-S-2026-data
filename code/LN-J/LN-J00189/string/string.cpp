#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int l=1,r=n;l<=n,r>=1,l<=r;){
        int L=a[l],R=a[r];
        if(L<R){
            if(c[l]!=c[r])ans+=a[l];
            a[r]-=a[l];
            l++;
        }
        if(L>R){
            if(c[l]!=c[r])ans+=a[r];
            a[l]-=a[r];
            r--;
        }
        if(L==R){
            if(c[l]!=c[r])ans+=a[l];
            l++;r--;
        }
    }
    cout<<ans;
    return 0;
}
