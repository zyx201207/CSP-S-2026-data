#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,m,a[N],ans;
bitset<N> del;
bitset<N> trydel;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=n;
    for(int i=30;i>=0;i--){
        trydel=0;
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!del[j] && !((a[j]>>i)&1)){
                //cout<<"trydel "<<i<<' '<<j<<'\n';
                cnt++;
                trydel[j]=1;
            }
        }
        if(sum-cnt>=m){
            //cout<<"del "<<sum<<' '<<cnt<<'\n';
            del|=trydel;
            sum-=cnt;
            ans+=(1<<i);
        }
    }
    cout<<ans;
    return 0;
}
