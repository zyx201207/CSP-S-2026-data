#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int a[N];
int n,m;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int t=a[(n+1)/2];

    int beg=(n+1)/2;
    while(beg<=n&&a[beg+1]==t){
        beg++;
    }

    int ans=0;
    for(int i=beg;i>=1;i--){
        if(m>=t-a[i]){
            ans++;
            m=m-(t-a[i]);
        }else{
            break;
        }
    }
//all right

    if(m>=ans*(a[beg+1]-t)){
        //hai neng zheng
        for(int i=beg+1;i<=n;i++){
            if(ans*(a[i]-t)<=m){
                m=m-ans*(a[i]-t);
                ans++;
                t=a[i];
            }else{
                break;
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}

