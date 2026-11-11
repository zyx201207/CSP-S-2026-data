#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum=0,ans=0;
struct duan{
    char c;
    ll nu;
}d[200005];
ll sq[200005],sh[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].nu>>d[i].c;
        sum+=d[i].nu;
        sq[i]=sq[i-1]+d[i].nu;
    }
    for(int i=n;i>=1;i--){
        sh[n-i+1]=sh[n-i]+d[i].nu;
    }
    ll t=sum/=2;
    ll iq=1,ih=1;
    ll nuq=0,nuh=0;
    ll ta=0;
    while(1){
        if(ta>=t){
            break;
        }
        if(sq[iq]<=sh[ih]&&d[iq].c!=d[n-ih+1].c){
            ans+=min(sq[iq],t)-ta;
            ta=sq[iq];
            iq++;
        }
        else if(sq[iq]>sh[ih]&&d[iq].c!=d[n-ih+1].c){
            ans+=min(sh[ih],t)-ta;
            ta=sh[ih];
            ih++;
        }
        if(d[iq].c==d[n-ih+1].c){
            if(sq[iq]<=sh[ih]){
                ta=sq[iq];
                iq++;
            }
            else{
                ta=sh[ih];
                ih++;
            }
        }
    }
    cout<<ans;
    return 0;
}
