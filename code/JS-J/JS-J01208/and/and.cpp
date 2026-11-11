#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
vector<ll>v[2];
bool f;
int main(){
    //g++ a.cpp -o a -o2 -std=c++14 
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    if(m==1){
        ll ma=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
        }
        cout<<ma;
    }
    else if(n==m){
        ll ans;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0)ans=a[i];
            else ans=ans&a[i];
        }
        cout<<ans;
    }
    else{
        for(int i=0;i<n;i++){cin>>a[i];v[f].push_back(a[i]);}
        for(int i=30;i>=0;i--){
            int cnt=0;
            ll x=(1<<i);
            for(int j=0;j<v[f].size();j++){
                if(v[f][j]&x){cnt++;v[!f].push_back(v[f][j]);}
            }
            if(cnt>=m){
                //cout<<x<<"\n";
                v[f].clear();
                f=!f;
            }
            else{
                v[!f].clear();
            }
        }
        if(v[f].empty())cout<<0;
        else {
            ll ans=v[f][0];
            for(int i=1;i<v[f].size();i++){
                //cout<<v[f][i]<<"\n";
                ans=ans&v[f][i];
            }
            cout<<ans;
        }
    }
    return 0;
}