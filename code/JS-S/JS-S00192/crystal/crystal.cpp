#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
int n;
ll m,num;
ll a[N],b[N];
ll mx=1;

ll maxe(ll a,ll b){
    if(a>b)return a;
    else return b;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    ll cha;
    int f=1;//dencha

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            cha=a[2]-a[1];
        }
        if(a[i]-a[i-1]!=cha){
            f=0;//putong
        }
    }
    if(f==1&&cha==0){
        f=-1;
    }
    ll ans;
    sort(a+1,a+1+n);
    if(m==0){
        ll maxn=1,num=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                num++;
            }
            if(a[i]!=a[i-1]){

                maxn=maxe(maxn,num);
                num=1;
            }
        }
        cout<<maxn;
        return 0;
    }

    if(f==1){
        if(m==0)cout<<n;
        else cout<<n-1;
        return 0;
    }
    if(f==-1){
        ll ans;
        for(int i=1;i<=m;i++){
            ll p=(a[i]*i)-(a[1]+a[i])*i/2;
            if(p<m){
                ans=i;
                continue;
            }
            if(p==m){
                ans=i;
                break;
            }
            if(p>m){
                break;
            }
        }
        cout<<ans;
    }
    ll maxn=1,num=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            num++;
        }
        if(a[i]!=a[i-1]){
            maxn=maxe(maxn,num);
            num=1;
        }
    }
    if(f==0){
            ll mx=maxn;
            for(int i=2;i<=n;i++){
                bool o=1;
                ll k=mx;
                while(o&&i-k>=1){ll op=0;
                    for(ll j=1;j<=k;j++){
                        op=op+(a[i]-a[i-j]);
                    }
                    //cout<<op<<" "<<k<<'\n';
                    if(op<=m&&mx<k){
                        mx=k;
                        //cout<<'\n'<<op<<" "<<k<<'\n'<<'\n';
                    }
                    if(op>m)o=0;
                    k++;
                }
            }
            cout<<mx+1;
            return 0;
        }
    return 0;
}
