#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
int n,m;
int a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    bool f=1;
    for(int i=2;i<=n;i++){
        if(c[i]!=c[i-1]){
            f=0;
            break;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(f==1){
        cout<<0;
        return 0;
    }
    int l=1,r=n;
    int ans=0;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]=a[l]-a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]=a[r]-a[l];
                l++;
            }
            else {
                r--;
                l++;
            }
        }
        else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]=a[l]-a[r];
                r--;
            }
            else if(a[l]<a[r]){
                ans+=a[l];
                a[r]=a[r]-a[l];
                l++;
            }
            else {
                ans+=a[l];
                r--;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
