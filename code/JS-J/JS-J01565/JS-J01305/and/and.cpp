#include<bits/stdc++.h>
using namespace std;
const int N=200005;
bool a[N][31],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int d=0;x;d++){
            a[i][d]=x&1;
            x>>=1;
        }
    }
    memset(b,true,sizeof(b));
    int cnt,ans=0;
    for(int d=30;d>=0;d--){
        cnt=0;
        for(int i=1;i<=n;i++)if(b[i]&&a[i][d])cnt++;
        if(cnt>=m){
            for(int i=1;i<=n;i++)if(!a[i][d])b[i]=false;
            ans+=1<<d;
        }
    }cout<<ans;
    return 0;
}
