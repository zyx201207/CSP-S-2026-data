#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    char c;
    vector<pair<int,char>>v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    int a=0,b=n-1;
    while(b-a>0){
        int x=min(v[a].first,v[b].first);
        if(v[a].second!=v[b].second)ans+=x;
        if(v[a].first==x)a++;
        else v[a].first-=x;
        if(v[b].first==x)b--;
        else v[b].first-=x;
    }
    cout<<ans;
    return 0;
}
