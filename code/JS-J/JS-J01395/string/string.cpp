#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    int a[n+5];
    char c[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }
            else if(a[r]>a[l]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else{
                ans+=a[l];
                l++;
                r--;
            }
        }
        else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[r]>a[l]){
                a[r]-=a[l];
                l++;
            }
            else{
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
