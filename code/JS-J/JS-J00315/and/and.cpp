#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200050],b[200050][32];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int x=a[i];
        for(int j=1;j<=30;j++){
            b[i][j]=(x&1);
            x>>=1;
            if(!x)break;
        }
    }
/*    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            cout<<b[i][j];
        }
        cout<<"\n";
    }*/
    set<int>st;int j;
    for(j=30;j>=1;j--){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=b[i][j];
        if(cnt<m)continue;
        for(int i=1;i<=n;i++){
            if(b[i][j]==1){
                st.insert(i);
            }
        }
        break;
    }
    if(j==0){
        cout<<0;
        return 0;
    }
    for(;j>=1;j--){
        int cnt=0;
        for(auto e:st)cnt+=b[e][j];
        if(cnt<m)continue;
        vector<int>v(0);
        for(auto e:st){
            if(b[e][j]==0){
                v.push_back(e);
            }
        }
        for(auto e:v)st.erase(st.lower_bound(e));
        if(st.size()==m)break;
    }
    vector<int>v(0);
    for(auto e:st){
        v.push_back(e);
//        cout<<e<<" ";
        if(v.size()==m)break;
    }
    ans=a[v[0]];
    for(int i=1;i<v.size();i++)ans=(ans&a[v[i]]);
    cout<<ans;
    return 0;
}
