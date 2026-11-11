#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int a[200005];
int cnt;
int bit[33][200005],bcnt[50];
bool st[200005];
void solve(){
    bitset <64> bs;
    for(int i=1;i<=n;i++){
        bs=a[i];
        for(int j=31;j>=0;j--){
            bit[j][i]=bs[j];
      //      bcnt[j]+=bs[j];
        }
    }
    bs=0;
    int ans=0;
    for(int j=31;j>=0;j--){

        for(int i=1;i<=n;i++){
            if(st[i])
                continue;
            bcnt[j]+=bit[j][i];

        }
        if(bcnt[j]>=m)
        {
            ans+= 1<<j;
            for(int i=1;i<=n;i++){
                if(!bit[j][i])
                    st[i]=1;
            }
        }
    }
    cout<<ans;
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)
            cnt++;

    }
    if(n==m){
        for(int i=1;i<=n;i++){
            a[1]&=a[i];
        }
        cout<<a[1];
        return 0;
    }
    if( m+cnt>n){
        cout<<0;
        return 0;
    }

    solve();


}
