#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int l=1,r=n;
    while(1){
        if(l>=r) break;
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[l]==a[r]){
                l++;
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
        }
        else if(c[l]!=c[r]){
            if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }
            else if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
