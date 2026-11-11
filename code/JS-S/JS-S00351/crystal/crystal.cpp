#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,a[N],m,w[N],mx;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n*n<=1e9){
        for(int i=1;i<=n;i++){
            int t=m;
            memset(w,0,sizeof(w));
            for(int j=1;j<=n;j++) w[j]=abs(a[i]-a[j]);
            sort(w+1,w+n+1);
            for(int i=1;i<=n;i++) cout<<w[i]<<' ';
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(t<w[j]) break;
                t-=w[j];
                cout<<w[j]<<' ';
                cnt++;
            }
            cout<<'\n';
            mx=max(mx,cnt);
        }
        cout<<mx;
    }
    else {
        int mid=(n+1)/2;
        for(int j=1;j<=n;j++) w[j]=abs(a[mid]-a[j]);
        sort(w+1,w+n+1);
        int cnt=0,t=m;
        for(int j=1;j<=n;j++){
            if(t<w[j]) break;
            t-=w[j];
            cout<<w[j]<<' ';
            cnt++;
        }
        cout<<'\n';
        mx=max(mx,cnt);
        cout<<mx;
    }
    return 0;
}
