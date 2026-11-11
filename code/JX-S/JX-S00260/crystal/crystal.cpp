#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
unsigned long long m,dlm;
long long a[N],mins=LONG_LONG_MAX,maxs=LONG_LONG_MIN;
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    dlm=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mins=min(mins,a[i]);
        maxs=max(maxs,a[i]);
    }
    if(n<=5000){
        int cnt=0,ans=0;
        sort(a+1,a+1+n,cmp);
        for(int i=mins;i<=maxs;i++){
            for(int o=1;o<=n;o++){
                cnt=0;
                if(a[o]>i){
                    for(int j=o-1;j>=1;j--){
                        if(i-a[j]>m) break;
                        m-=(i-a[j]);
                        cnt++;
                    }
                    break;
                }
            }
            ans=max(ans,cnt);
            m=dlm;
        }
        cout<<ans;
    }else{
        long long c=a[2]-a[1],i=1;
        m/=c;
        while(1){
            long long pd=i*(i+1);
            pd/=2;
            if(pd==m){
                cout<<i+1;
                return 0;
            }else if(pd>m){
                cout<<i;
                return 0;
            }
            i++;
        }
    }
    return 0;
}
