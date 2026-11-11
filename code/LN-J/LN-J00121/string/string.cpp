#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,char>>v(200005);
    int sum=0;
    for(int i=0;i<n;i++){
        int a;char c;
        cin>>a>>c;
        v[i]={a,c};
        sum+=a;
    }
    char c[200005];
    int l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].first;j++){
            c[l]=v[i].second;
            l++;
        }
    }
    int ans=0;
    for(int i=0;i<sum;i++){
        if(c[i]!=c[sum-i-1]){
            ans++;
        }
    }
    cout<<ans/2;
}