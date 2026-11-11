#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[200005][35];
ll n,m;
ll a[200005];
bool vis[200005];
ll ans;
ll exp_2[35];
int main(){
    //ji1 qi4 fan4 bing4 du2 bu4 quan2 shu4 ju4 :(
    // why this machine can only read 4095 byte per line :(
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    cin>>n>>m;
    getchar();
    for(int i=0;i<n;i++){
            cin>>a[i];
        //cout<<i;
        ll c=a[i];
        int now=0;
        while(c>0){
            b[i][now]=c%2;
            c/=2;
            now++;
        }
    }
    //for(int i=0;i<n;i++)cout<<a[i]<<' ';
    /*for(int i=0;i<n;i++){
        for(int j=0;j<32;j++)
            cout<<b[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i=0;i<n;i++){
        vis[i]=1;
    }
    exp_2[0]=1;
    for(int i=1;i<33;i++){
        exp_2[i]=2*exp_2[i-1];
    }
    for(int j=33;j>=0;j--){
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==1)cnt+=b[i][j];
        }
        if(cnt>=m){
            ans+=exp_2[j];
            for(int i=0;i<n;i++){
                if(vis[i]==1&&b[i][j]==0)vis[i]=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
