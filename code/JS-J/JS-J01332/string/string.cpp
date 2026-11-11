#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int pt[200005];
char dc[200005];
int sum[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sim=0;
    for(int i=1;i<=n;i++){
        cin>>pt[i]>>dc[i];
        sim+=pt[i];
        sum[i]=sum[i-1]+pt[i];
    }
    int l=0,r=n+1;
    int sigl=0,sigr=0;
    int ans=0;
    while(l<r){
        if(sigl<sigr){
            l++;
            int last=sigl;
            sigl+=pt[l];
            if(dc[l]!=dc[r]){
                ans+=min(sigl,sigr)-last;
            }
        }
        else{
            r--;
            int last=sigr;
            sigr+=pt[r];
            if(dc[l]!=dc[r]){
                ans+=min(sigl,sigr)-last;
            }
        }
    }
    cout<<ans;
    return 0;
}
