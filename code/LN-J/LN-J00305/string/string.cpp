#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,a[500005],L=0;
char c[500005];
signed main(){
    qrw;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],L+=a[i];
    int lp=0,rp=L+1,ld=1,rd=n,ans=0;
    while(ld<=rd){
        if(lp<=(L-rp+1)){
            // if(rd==n) 0;
            // else 
                ans+=((bool)(c[ld]!=c[rd+1]))*abs(min(lp+a[ld],(L-rp+1))-lp);
            // cout<<c[ld]<<" "<<c[rd+1]<<" "<<min(lp+a[ld],(L-rp+1))<<" "<<abs(min(lp+a[ld],(L-rp+1))-lp)<<endl;
            lp+=a[ld],ld++;
        }
        else{
            ans+=((bool)(c[ld-1]!=c[rd]))*abs(min(lp,(L-(rp-a[rd])+1))-(L-rp+1));
            // cout<<c[ld-1]<<" "<<c[rd]<<" "<<min(lp,(L-(rp-a[rd])+1))<<" "<<abs(min(lp,(L-(rp-a[rd])+1))-(L-rp+1))<<endl;
            rp-=a[rd],rd--;
        }
        // cout<<L<<" "<<ld<<":"<<rd<<" "<<lp<<":"<<rp<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}