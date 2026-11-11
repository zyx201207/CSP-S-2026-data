#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n;
long long a[MAXN];
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
    int l=0,r=n+1;
    long long llen=0,rlen=0,ans=0;
    while(l+1<r){
        if(llen<rlen){
            l++;
            if(c[l]!=c[r]){
                ans+=min(a[l],rlen-llen);
            }
            llen+=a[l];
        }else if(llen>rlen){
            r--;
            if(c[r]!=c[l]){
                ans+=min(a[r],llen-rlen);
            }
            rlen+=a[r];
        }else{
            l++;
            r--;
            if(c[l]!=c[r]){
                ans+=min(a[l],a[r]);
            }
            llen+=a[l];
            rlen+=a[r];
        }
        //cout<<llen<<' '<<rlen<<' '<<ans<<endl;
    }
    cout<<ans;

    return 0;
}
