#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
int n,a[maxn];
ll pre[maxn];
char c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n;
    ll len=0,ans=0;
    while(l<r){
        if(pre[l]<=pre[n]-pre[r-1]){
            if(c[l]!=c[r]){
                ans+=pre[l]-len;
            }
            len=pre[l];
            l++;
        }
        else{
            if(c[l]!=c[r]){
                ans+=(pre[n]-pre[r-1])-len;
            }
            len=(pre[n]-pre[r-1]);
            r--;
        }
    }
    cout<<ans;
    return 0;
}