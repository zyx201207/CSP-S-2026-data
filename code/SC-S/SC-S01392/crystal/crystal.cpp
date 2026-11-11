#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,p=i,len=1;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(1LL*(i-mid))-(s[i-1]-s[mid-1])<=m){
                p=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        len+=i-p;
        ans=max(ans,len);
    }
    cout<<ans;
}