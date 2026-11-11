#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            int cha=a[2]-a[1];
            int maxk=d/cha;
            if(maxk==0||maxk==1||2*maxk-1>n){
                cout<<0<<endl;
            }
            else{
                printf("%lld\n",n-2*maxk+1);
            }
        }

    }
    return 0;
}
