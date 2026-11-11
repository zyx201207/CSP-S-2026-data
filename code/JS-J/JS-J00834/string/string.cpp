#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    vector<ll> a(n);
    vector<char> c(n);
    ll sum;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }

    int l=0,r=n-1;
    ll ans=0;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]==a[r]){
                l++;
                r--;
            }else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else{
                a[r]-=a[l];
                l++;
            }
        }else{
           if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }else if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else{
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
