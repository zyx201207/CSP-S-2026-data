#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
int check(int idx){
    int k=a[idx];
    int idx2=idx;
    int cnt=0;
    int ans=0;
    while(idx2>=1){
        cnt+=k-a[idx2];
        if(cnt>m){
            break;
            ans--;
        }
        ans++;
        idx2--;
    }
    if(cnt<m){
        return -1;
    }
    else return ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool flag=0;
    cin>>a[1]>>a[2];
    int W=a[2]-a[1];
    for(int i=3;i<=n;i++){
        cin>>a[i];
        if(a[i]-a[i-1]!=W){
            flag=1;
        }
    }
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    if(!flag){
        for(int i=1;i<=n;i++){
            int k=(a[1]+a[i])*i/2;
            if(m>=k){
                cout<<i+1;
                return 0;
            }
        }
    }

    int maxn=-20;
    for(int i=n;i>=1;i--){
        //cout<<"check["<<i<<"]:"<<check(i)<<'\n';
        if(check(i)==-1){
            cout<<maxn;
            return 0;
        }
        else{
            maxn=max(maxn,check(i));
        }
    }
}