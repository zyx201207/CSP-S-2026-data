#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],l[200005],r[200005];
char c[200005];
ll tot=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        l[i]=1+tot;
        r[i]=tot+a[i];
        tot+=a[i];
    }
    ll LL = tot/2;
    queue<pair<ll,ll> > q1;
    queue<pair<ll,ll> > q2;
    queue<char> qc1;
    queue<char> qc2;
    for(int i=1;i<=n;++i){
        if(r[i]>=LL){
            q1.push({l[i],LL});
            qc1.push(c[i]);
            break;
        }
        q1.push({l[i],r[i]});
        qc1.push(c[i]);
    }
    for(int i=n;i>=1;--i){
        ll nl=tot+1-r[i];
        ll nr=tot+1-l[i];
        //cout<<'\n'<<r[i]<<' '<<LL<<' '<<LL+1-r[i]<<' '<<nl<<'\n';
        if(nr>=LL){
            q2.push({nl,LL});
            qc2.push(c[i]);
            break;
        }
        q2.push({nl,nr});
        qc2.push(c[i]);
    }

    while(!q1.empty()&&!q2.empty()){
        ll &l1=q1.front().first;
        ll &r1=q1.front().second;
        ll &l2=q2.front().first;
        ll &r2=q2.front().second;
        //auto [l1,r1] =q1.front();
        //auto [l2,r2] =q2.front();
        if(r1>r2){
            if(qc2.front()!=qc1.front()) ans+=(r2-l2+1);
            l1=r2+1;
            q2.pop();
            qc2.pop();
        }else if(r2>r1){
            if(qc1.front()!=qc2.front()) ans+=(r1-l1+1);
            l2=r1+1;
            q1.pop();
            qc1.pop();
        }else{
            if(qc1.front()!=qc2.front()) ans+=(r2-l2+1);
            q1.pop();
            q2.pop();
            qc1.pop();
            qc2.pop();
        }
    }
    cout<<ans<<endl;

    /*
    cout<<'\n';
    while(!q1.empty()){
        printf("%lld %lld",q1.front().first,q1.front().second);
        q1.pop();
    }
    cout<<'\n';
    while(!q2.empty()){
        printf("%lld %lld",q2.front().first,q2.front().second);
        q2.pop();
    }
    cout<<'\n';
    */
    return 0;
}
