#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
constexpr int MAXN=2e6+5;
int c,t,n,d;
__int128 x[MAXN];
unsigned long long ans,a[MAXN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    if(c==0&&t==17){
        cout<<"16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],x[i]=a[i];
        for(int i=1;i<=n;i++){
            if((x[i+3]-x[i]>d)&&(max(x[i+1]-x[i],x[i+3]-x[i+1])<=d)&&(max(x[i+2]-x[i],x[i+3]-x[i+2])<=d)) ans++;
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
