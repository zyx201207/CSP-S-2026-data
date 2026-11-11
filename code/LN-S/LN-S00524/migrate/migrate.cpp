// this is NO.3 : migrate 
#include<bits/stdc++.h>
using namespace std;
long long x[2000005],n,d;

int pan(int st,int en){
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>T>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(pan(i,j)==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}