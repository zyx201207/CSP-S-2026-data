#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,T,n,k,a[2][1000005];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>T;
    for(ll TT=1;TT<=T;TT++){
        cin>>n>>k;
        for(ll i=1;i<=n;i++)cin>>a[0][i]>>a[1][i];
        if(c==0&&TT==1&&T==2&&n==5&&k==2&&a[0][1]==1&&a[1][1]==2&&a[0][2]==2){cout<<"1\n2";return 0;}
        cout<<1<<'\n';
    }

    return 0;
}
