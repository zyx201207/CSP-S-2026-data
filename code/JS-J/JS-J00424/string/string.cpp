#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2000005];
char c[2000005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }
        if(a[l]==a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            l++,r--;
        }
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }
    }
    cout<<ans;
}
