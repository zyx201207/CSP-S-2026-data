#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin >>n;
    ll s=0;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>c[i];
        s=(s+a[i])%2;
    }
    ll ans=0;
    for(int l=1,r=n;l<=r;){
        if(a[l]==a[r]){
            if(c[l]!=c[r])ans+=a[l];
            a[l]=a[r]=0;l++,r--;
        }else if(a[l]<a[r]){
            a[r]-=a[l];
            if(c[l]!=c[r])ans+=a[l];
            l++;
            a[l-1]=0;
        }else{
            a[l]-=a[r];
            if(c[l]!=c[r])ans+=a[r];
            r--;
            a[r+1]=0;
        }
        // cout<<l<<" "<<r<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

5 
123 a
456 b
100 c
100 c
200 b
*/