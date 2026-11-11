#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[500005],n,m;
void d(vector<ll> a,int x){
    vector<ll>b;
    for(int i=x-1;i<n;i++){
        b.push_back(a[i]);
        for(int j=0;j<i-x;j++){
            if(b[j]==a[i]){
                b[j]=b[b.size()-2]=-1;
                break;
            }
        }
    }
    bool flag=1;
    for(auto i:b){
        if(i==-1){flag=!flag;continue;}
        if(flag)ans[i]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        d(a,i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
