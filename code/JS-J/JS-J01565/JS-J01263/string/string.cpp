#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int nt,n,cnt[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>nt;
    for(int i=1;i<=nt;i++){
        int x;char t;
        cin>>x>>t;
        if(c[n]!=t){
            n++;
            c[n]=t;
            cnt[n]=x;
        }
        else{
            cnt[n]+=x;
        }
    }
    int l=1,r=n,ans=0;
    while(l<r){
        if(cnt[l]==cnt[r]){
            if(c[l]!=c[r]){
                ans+=cnt[r];
            }
            l++,r--;
        }
        else if(cnt[l]>cnt[r]){
            if(c[l]==c[r]){
                cnt[l]-=cnt[r];
                r--;
            }
            else{
                ans+=cnt[r];
                cnt[l]-=cnt[r];
                cnt[r]=0;
                r--;
            }
        }
        else{
            if(c[l]==c[r]){
                cnt[r]-=cnt[l];
                l++;
            }
            else{
                ans+=cnt[l];
                cnt[r]-=cnt[l];
                cnt[l]=0;
                l++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}