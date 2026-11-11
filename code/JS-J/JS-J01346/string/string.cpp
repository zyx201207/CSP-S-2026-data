#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2*1000000+10;

int n,lenn,ans;
pair<char,int> a[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }
    int j;
    for(int i=1;i<=n;i++){
        if(a[i-1].second!=0){
            if(a[i-1].first!=a[n-i+1].first){
                ans+=a[i-1].second;
            }
            j+=a[i-1].second;
            if(j>=lenn/2){
                cout<<ans<<endl;
                return 0;
            }
            a[n-i+1].second-=a[i-1].second;
            a[i-1].second==0;
        }else if(a[n-i+2].second!=0){
                if(a[i]!=a[n-i+2]){
                    ans+=a[n-i+2].second;
                }
                j+=a[n-i+2].second;
                if(j>=lenn/2){
                    cout<<ans<<endl;
                    return 0;
                }
                a[i].first-=a[n-i+2].second;
                a[n-i+2].second==0;
            }
        if(a[i].first==a[n-i+1].first){
            j+=min(a[i].second,a[n-i+1].second);
            if(j>=lenn/2){
                cout<<ans<<endl;
                return 0;
            }
            if(a[i].second>a[n-i+1].second){
                    a[i].second-=a[n-i+1].second;
                    a[n-i+1].second=0;
            }else{
                a[n-i+1].second-=a[i].second;
                a[i].second=0;
            }
        }else{
            ans+=min(a[n-i+1].second,a[i].second);
            j+=min(a[i].second,a[n-i+1].second);
            if(j>=lenn/2){
                cout<<ans<<endl;
                return 0;
            }
            if(a[i].second>a[n-i+1].second){
                    a[i].second-=a[n-i+1].second;
                    a[n-i+1].second=0;
            }else{
                a[n-i+1].second-=a[i].second;
                a[i].second=0;
            }
        }
    }
    return 0;
}
