#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2000005;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        bool flag=1;
        int dd;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i==2)dd=x[i]-x[i-1];
            if(i>2&&x[i]-x[i-1]!=dd)flag=0;
        }
        if(flag){
            int k1=d/dd;
            int k2=2*d/dd;
            int ans=0;
            for(int i=1;i+k1<=n;i++){
                ans+=max(0,(k2-k1-1));
            }
        }else{
            cout<<d/2<<endl;
        }

    }
    return 0;
}
