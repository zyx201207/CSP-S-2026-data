#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int cha[2000005];
int sum[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n,d;
    cin>>c>>t;
    while(t--){
        bool f1=true;
        //cout<<t<<'\n';
        cin>>n>>d;
        //cout<<n<<d<<"***"<<'\n';
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>2){
                if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                    f1=false;
                }
            }
        }
        if(f1){
            int ans=0;
            int gc=a[2]-a[1];
            if(gc>d){
                cout<<"0"<<'\n';
                continue;
            }
            for(int i=2;i<=n/2;i++){
                if(gc*i>d)break;
                if(gc*i<=d && gc*(2*i-1)>d){
                    ans+=n-(i*2-1);
                }
            }
            cout<<ans<<'\n';
        }else{
            int minn=1;
            for(int i=1;i<=n;i++){
                cha[i]=a[i]-a[i-1];
                minn=min(a[i],minn);
            }
            if(minn<0){
                for(int i=1;i<=n;i++){
                    a[i]+=abs(minn)+1;
                }
            }

            for(int i=2;i<=n;i++){
                sum[i]=sum[i-1]+cha[i];
            }
            int num=0;
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    int ans=0;
                    for(int k=i+1;k<j;k++){
                        if(sum[k]-sum[i]<=d && sum[j]-sum[k]<=d){
                            ans++;
                        }
                    }
                    if(ans==2){
                        num++;
                    }
                }
            }
            cout<<num<<'\n';
        }
    }
    return 0;
}
