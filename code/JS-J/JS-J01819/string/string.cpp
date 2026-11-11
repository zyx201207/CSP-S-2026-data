#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
struct node{
    int x;
    char c;
};
node a[N];
ll pre[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        pre[i]=pre[i-1]+a[i].x;
    }
    ll l=1,r=pre[n];
    int lbel=1,rbel=n;
    ll ans=0;
    while(lbel<=rbel){
        ll llen=pre[lbel]-l+1;
        ll rlen=r-pre[rbel-1];
        if(llen==rlen){
            ans+=llen*(a[lbel].c!=a[rbel].c);
            lbel++,rbel--;
            l=pre[lbel-1]+1,r=pre[rbel];
        }else if(llen<rlen){
            ans+=llen*(a[lbel].c!=a[rbel].c);
            lbel++;
            ll len=pre[lbel-1]+1-l;
            l+=len;r-=len;
        }else{
            ans+=rlen*(a[lbel].c!=a[rbel].c);
            rbel--;
            ll len=r-pre[rbel];
            r-=len;l+=len;
        }
    }
    cout<<ans;
    return 0;
}
