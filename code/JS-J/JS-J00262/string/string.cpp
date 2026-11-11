#include<bits/stdc++.h>
using namespace std;
long long a[2000005],n;
char b[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        if(b[l]!=b[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]<a[r]){
           a[r]-=a[l];
            l++;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r]){
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
