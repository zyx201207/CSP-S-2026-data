#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=2e5+10;
const int INF=1e9+5;
ll a[N];
ll b[N];
ll c[N];
ll cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        ll maxa=0;
        for(int j=0;j<n;j++){
            if(a[j]>maxa){
                maxa=a[j];
                a[j]=-1;
            }
        }
        b[i]=maxa;
    }
    for(int i=0;i<m;i++){
        c[i]=b[i];
    }
    cnt=c[0];
    for(int i=1;i<m;i++){
        cnt= cnt&c[i];
    }
    cout<<cnt<<endl;
    return 0;
}
