#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long a[n];
    char c[n];
    long long ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> c[i];
    }
    int l=0,r=n-1;
    while(l<=r){
        if(c[l]!=c[r]){
            if(a[l]<=a[r]){
                a[r]-=a[l];
                ans+=a[l];
                a[l]=0;
                l++;
                if(a[r]==0){
                    r--;
                }
            }else{
                a[l]-=a[r];
                ans+=a[r];
                a[r]=0;
                r--;
            }
        }else{
            if(a[l]<=a[r]){
                a[r]-=a[l];
                a[l]=0;
                l++;
                if(a[r]==0){
                    r--;
                }
            }else{
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}