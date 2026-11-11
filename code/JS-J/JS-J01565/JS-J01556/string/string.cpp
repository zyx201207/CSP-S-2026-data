#include<iostream>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans,a[N];
char e[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>e[i];
    int l=1,r=n;
    while(l<r){
        if(e[l]!=e[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }else if(a[l]==a[r]){
                ans+=a[r];
                l++;r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]==a[r]){
                l++;r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
