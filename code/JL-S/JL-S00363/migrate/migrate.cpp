#include<bits/stdc++.h>
using namespace std;
const int maxn=5500;
long long n,d,c,t,b[maxn],cnt,ans;
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        ans=0;
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        if(c==11||c==12){
            if(d%2==0){
                if(d>=n){
                    cout<<n/2;
                }
            }
            else{
                cout<<0<<endl;
            }
        }
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    for(int o=0;o<n;o++){
                        if(b[j]-b[l]==b[o]-b[k]&&b[j]-b[l]<=d&&b[o]-b[k]<=d)
                            cnt++;
                    }
                }
            }
        }
        if(cnt==2){
            ans++;
        }
        cnt=0;
        cout<<ans<<endl;
    }
    return 0;
}

