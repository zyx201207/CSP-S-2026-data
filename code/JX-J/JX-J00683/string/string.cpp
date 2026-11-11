#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
char c[200005];
unsigned long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            } else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            } else{
                l++;r--;
            }
        } else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            } else if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            } else{
                ans+=a[l];
                l++;r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
