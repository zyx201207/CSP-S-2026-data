#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005],ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    l=1,r=n;
    while(1){
        if(l>=r){
            cout<<ans;
            return 0;
        }
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else ans+=a[r],r--,l++;
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else r--,l++;
        }
    }
}
