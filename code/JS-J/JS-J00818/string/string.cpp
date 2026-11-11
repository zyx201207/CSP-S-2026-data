#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char b[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    int ans=0;
    int l=1,r=n;
    while(l!=r){
        if(a[l]<a[r]){
            if(b[l]==b[r]){
                a[r]-=a[l];
                l++;
            }
            else{
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
        }
        else{
            if(b[l]==b[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
