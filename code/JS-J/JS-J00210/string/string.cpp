#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l,r;
    l=1;
    r=n;
    long long ans=0;
    while(l<=r){
        if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
        else if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        else if(a[l]==a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
