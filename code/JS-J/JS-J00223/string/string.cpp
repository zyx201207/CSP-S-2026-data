#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
int n;
int a[maxn];
char c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    ll l=1,r=n,ans=0;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }
        else{
            r--;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
