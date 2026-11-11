#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        long long pd1=0,pd2=0;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<4){
            cout<<0<<endl;
        }
        else{
            long long ad=x[2]-x[1];
            for(long long i=3;i<=n;i++){
                if(x[i]-x[i-1]!=ad){
                    pd1=1;
                }
            }
            for(long long i=2;i<n;i++){
                if(x[i]>=x[n]-d && x[i]<=x[1]+d){
                    pd2=1;
                }
            }
            if(pd1==0){
                if(d<ad){
                    cout<<0<<endl;
                }
                else if(d==ad){
                    cout<<0<<endl;
                }
                else{
                    long long aad=d/ad;
                    if(n-3-2*(aad-2)<=0){
                        cout<<0<<endl;
                    }
                    else{
                        cout<<n-3-2*(aad-2)<<endl;
                    }
                }
            }
            else if(pd2==0){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}

