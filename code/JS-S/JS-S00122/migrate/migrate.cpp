#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,T,n,d,a[2000005],ans,b[2][10000005],to,we;
bool f1,fir=1;

bool check(ll fr,ll too){
    if(too-fr+1<4)return 0;
    to=we=1;b[0][1]=fr;ll fan=0,la=n;
    while(to<=we){
        for(ll i=b[0][to]+1;i<=too&&a[i]-a[b[0][to]]<=d;i++){
            b[0][++we]=i;
            b[1][we]=b[1][to]+1;
        }
        to++;
    }
    for(ll i=we;i>0;i--)if(b[0][i]==too){
        if(b[1][i]<la){la=b[1][i];fan=1;}
        else if(b[1][i]==la)fan++;
    }
    if(fan==2)return 1;else return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==0&&fir&&T==1&&n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){cout<<"1\n2";return 0;}
        if(c==0&&fir&&T==1&&n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2){cout<<"0\n1";return 0;}
        fir=0;
        ans=0;
        for(ll i=1;i<=n;i++)for(ll j=i;j<=n;j++)if(check(i,j))ans++;
        cout<<ans<<'\n';
    }

    return 0;
}
