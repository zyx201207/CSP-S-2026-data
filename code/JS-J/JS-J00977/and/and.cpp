#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int m,n;
int c[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    if(m==1){
        cout<<c[n];
        return 0;
    }else if(m==n){
        int cnt = 0;
        for(int i=1;i<=n;i+=2){
            int d = c[i+1]&&c[i];
            cnt = d;
        }
        cout<<cnt;
        return 0;
    }



return 0;
}
