#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        long long n,d,cnt=0;
        long long a[100005]={};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]-a[i]+1==d*2&&j-i>=3){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
