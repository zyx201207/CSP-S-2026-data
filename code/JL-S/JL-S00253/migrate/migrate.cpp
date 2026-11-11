#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[2000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++)cin>>a[i];
        long long diff=0,last_diff=a[2]-a[1];
        bool flag=true;
        for(long long i=3;i<=n;i++){
            diff=a[i]-a[i-1];
            if(diff!=last_diff){
                flag=false;
                break;
            }
        }
        if(flag){
            if(last_diff>d)cout<<0<<'\n';
            else{
                long long cnt=1;
                while(last_diff*cnt<=d)cnt++;
                cnt--;
                if(2*cnt-1<=n){
                    long long tot=0;
                    for(long long i=1;i<cnt;i++){
                        long long num=cnt+i;
                        tot+=(n-num);
                    }
                    cout<<tot<<'\n';
                }
                else{
                    for(long long i=1;i<cnt;i++){
                        if(n+i>n){
                            cout<<i-1<<'\n';
                            break;
                        }
                    }
                }
            }
        }
        else cout<<0<<'\n';
    }
    return 0;
}
