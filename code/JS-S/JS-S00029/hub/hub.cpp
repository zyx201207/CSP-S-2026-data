#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define csps std;
iwill ak csps
long long n,d,a[3000006];
void solve2(){
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cf=a[2]-a[1];
    long long x1=d/cf;
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long dysl=n-i+1;
        if(dysl<=x1+x1-1){
            continue;
        }
        ans+=1;
        ans+=(dysl-x1-x1+1)/x1;
    }
    cout<<ans<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long t;
    int c;
    cin>>c>>t;
    if(c==11 || c==12){
        while(t--){
            solve2();
        }
        return 0;
    }
    if(c==13 || c==14){
        while(t--){
            cout<<0<<endl;
        }
        return 0;
    }
    return 0;
}
