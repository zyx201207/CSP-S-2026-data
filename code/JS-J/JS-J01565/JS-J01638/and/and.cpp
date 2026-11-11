#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    vector<vector<int>> b(n,vector<int> ((long long)35));
    vector<int> c(n,0);
    int k=0;
    while(mx){
        mx/=2;
        k++;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int x=a[j];
            x>>=i;
            x%=2;
            if(x==1){
                b[i].push_back(j);
                c[i]++;
            }
        }
    }
    map<int,int> mp;
    int ans=0;
    bool f=true,is=true,is1=false;
    vector<int> d;
    for(int i=k-1;i>=0;i--){
        if(c[i]<m) continue;
        if(c[i]==m&&f){
            ans=a[b[i][0]];
            for(int j=1;j<b[i].size();j++){
                ans&=a[b[i][j]];
            }
            cout<<ans;
            return 0;
        }
        f=false;
        for(int j=0;j<b[i].size();j++){
            if(mp[a[b[i][j]]]==1) d.push_back(a[b[i][j]]);
            if(mp[a[b[i][j]]]==0&&is) {mp[a[b[i][j]]]=1;is1=true;}
            if(d.size()==m){
                ans=d[0];
                for(int j=1;j<d.size();j++){
                    ans&=d[j];
                }
                cout<<ans;
                return 0;
            }
        }
        if(is1) is=false;
    }

    return 0;
}