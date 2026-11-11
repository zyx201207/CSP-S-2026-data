#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> a(n+2);
    vector <char> c(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll ans=0;
    for(int l=1,r=n;l<=r;){
        if(a[l]<a[r]){
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;
        }else if(a[l]>a[r]){
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }else if(a[l]==a[r]){
            if(c[l]!=c[r]) ans+=a[l];
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
