#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int c,t;
int n,d;
int a[N],h[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>d;
        int lst=0,cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            h[i]=a[i]-a[i-1];
            if(h[i]==lst||i<=2){
                cnt++;
                lst=h[i];
            }
        }
//        if(cnt==n){
//            cout<<lst<<'\n';
            if(d<2*lst){
                cout<<0<<'\n';
            }
            else{
                if(n-(d/lst)*2+1<0){
                    cout<<0<<'\n';
                }
                else{
                    cout<<n-(d/lst)*2+1<<'\n';
                }
            }
            continue;
//        }

    }
    return 0;
}

