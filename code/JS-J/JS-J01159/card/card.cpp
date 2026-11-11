#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll times[300005];
ll num[300005];
ll n,m;
ll card[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            times[card[j]]=1;
        }
        for(int j=1;j<=m;j++){
            num[j]+=times[j];
            times[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
