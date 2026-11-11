#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[2000005];char c[2000005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n;
    while(l<=r){
        if(c[l]==c[r]){
            int ls=min(a[l],a[r]);
            a[l]-=ls;a[r]-=ls;
            if(a[l]>a[r]){
                r--;
            }
            else if(a[l]<a[r]){
                l++;
            }
            else if(a[l]==a[r]){
                l++;r--;
            }
        }
        else{
            int ls=min(a[l],a[r]);
            ans+=ls;
            a[l]-=ls;a[r]-=ls;
            if(a[l]>a[r]){
                r--;
            }
            else if(a[l]<a[r]){
                l++;
            }
            else if(a[l]==a[r]){
                l++;r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
