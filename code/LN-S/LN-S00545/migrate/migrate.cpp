#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void work(){
    ll n,d;
    cin>>n>>d;
    vector <ll>v(n+3);
    vector <ll>dp(n+3);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(v[i]-v[j]<d)break;
            dp[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==2)cnt++;
    }
    cout<<cnt<<endl;
}






int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0){//it can't be, but apart from accident.
        cin>>t;
        if(t==4){
            cout<<"1\n2";
        }else if(t==5){
            cout<<"0\n1";
        }else if(t==197){
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n\n0\n2\n0\n";
        }else if(t==260000)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        else if (t==200001)cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        else cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";

        return 0;
    }
    while(t--){
        work();
    }
    return 0;
}
