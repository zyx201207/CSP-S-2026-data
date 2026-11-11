#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    char b[200005];
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        if (b[l]==b[r]){
            if (a[l]>a[r]){
                a[l]-=a[r];
                b[r]=0;
                r--;
            }else if (a[r]>a[l]){
                a[r]-=a[l];
                b[l]=0;
                l++;
            }else {
                a[r]=0;
                a[l]=0;
                r--;
                l++;
            }
        }else{
            if (a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                b[r]=0;
                r--;
            }else if (a[r]>a[l]){
                ans+=a[l];
                a[r]-=a[l];
                b[l]=0;
                l++;
            }else {
                ans+=a[r];
                a[r]=0;
                a[l]=0;
                r--;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
