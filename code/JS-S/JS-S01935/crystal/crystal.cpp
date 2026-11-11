#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=1;
    int ans=-1,cnt=0;
    while(1){
        int len=r-l+1;
        ans=max(ans,len);
        // cout<<l<<" "<<r<<" "<<cnt<<endl;
        if(len==0){
            if(a[r+1]-a[l]>m){
                l++;
                r++;
            }else{
                cnt+=a[r+1]-a[l];
                r++;
            }
        }else{
            if(cnt+len*(a[r+1]-a[r])>m){
                cnt-=a[r]-a[l];
                l++;
            }else{  
                cnt+=len*(a[r+1]-a[r]);
                r++;
            }
        }
        if(r>=n) {
            cout<<ans;
            return 0;
        }
    }
}
//15:30 AC