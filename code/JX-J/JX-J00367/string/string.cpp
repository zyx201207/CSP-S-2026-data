#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char c[200010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    for(;l<r;){
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                r--;
                continue;
            }
            else{
                a[r]-=a[l];
                a[l]=0;
                l++;
                continue;
            }
        }
        else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
                continue;
            }
            else{
                ans+=a[l];
                a[r]-=a[l];
                a[l]=0;
                l++;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
