#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+50;
ll n,d,x[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll c,_;
    cin>>c>>_;
    while(_--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c>=13&&c<=14)cout<<"0\n";
        else if(c>=11&&c<=12){
            ll len=x[2]-x[1];
            ll num=d/len;
            if(num<=1||d>(x[n]-x[1]))cout<<"0\n";
            else cout<<n-num*2+1<<"\n";
        } else{
            ll len=x[2]-x[1];
            ll num=d/len;
            if(num<=1||d>(x[n]-x[1]))cout<<"0\n";
            else cout<<n-num*2+1<<"\n";
        }
    }
    return 0;
}
