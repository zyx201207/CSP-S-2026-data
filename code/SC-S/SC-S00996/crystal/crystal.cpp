#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N],res[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    res[i]=res[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-res[i]+res[mid-1]<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }   
    cout<<ans;  
    return 0;
}