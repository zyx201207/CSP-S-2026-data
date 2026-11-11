#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            int k=min(a[l],a[r]);
            a[l]-=k;
            a[r]-=k;
            if(a[l]==0) l++;
            if(a[r]==0) r--;
        }else{
            ans+=min(a[l],a[r]);
            int k=min(a[l],a[r]);
            a[l]-=k;
            a[r]-=k;
            if(a[l]==0) l++;
            if(a[r]==0) r--;
        }
    }cout<<ans;
    return 0;
}
