#include<iostream>
using namespace std;
const int N=2*1e6+10;
int c,t,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,L=1,R=4,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int delta=a[2]-a[1];
        if(2*delta>d){
            cout<<0<<endl;
        }
        if(d%delta==0){
            int p=d/delta;
            while(R<=n){
                R=2*p+L-1;
                ans+=p-1;
                L++;
            }
            cout<<ans-1;
        }
//ran jin le
    }
    return 0;
}
/* wo yao shang mi huo xing wei da shang */
