#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    bool okA=true,okB=true;
    long long diff=0,last_diff=a[2]-a[1];
    for(long long i=1;i<=n;i++){
        if(a[i]!=i){
            okA=false;
            break;
        }
    }
    for(long long i=3;i<=n;i++){
        diff=a[i]-a[i-1];
        if(diff!=last_diff){
            okB=false;
            break;
        }
    }
    if(okA){
        long long tot=0;
        for(long long i=1;i<=n;i++){
            if(tot+i>m){
                cout<<i<<'\n';
                return 0;
            }
            else tot+=i;
        }
        cout<<n<<'\n';
        return 0;
    }
    if(okB){
        long long tot=0;
        for(long long i=1;i<=n;i++){
            if(tot+last_diff*i>m){
                cout<<i<<'\n';
                return 0;
            }
            else tot+=last_diff*i;
        }
        cout<<n<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    long long maxn=0;
    for(long long i=2;i<=n;i++){
        long long sum=0;
        bool flag=false;
        for(long long j=i-1;j>=1;j--){
            long long diff=a[i]-a[j];
            if(sum+diff>m){
                maxn=max(maxn,i-j);
                flag=true;
                break;
            }
            else sum+=diff;
        }
        if(!flag)maxn=max(maxn,i);
    }
    cout<<maxn<<'\n';
    return 0;
}
