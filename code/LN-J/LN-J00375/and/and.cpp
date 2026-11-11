#include <iostream>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],b[N];
void in(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    in();
    //freopen("and3.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=-2e9;
    for(int i=0;i<(1<<n);i++){
            int cnt=0,res=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                cnt++;
                if(cnt==1) res=a[j];
                else res=res&a[j];
            }
        }
       if(cnt==m){
            ans=max(ans,res);
       }
    }
    cout<<ans;
  return 0;
}
//5 3
//2 31 3 1 15 7
//4 2
//2 3 15 12 12
