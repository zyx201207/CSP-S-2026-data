#include <bits/stdc++.h>
using namespace std;
int t,p;
char w;
long long q,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    vector<pair<int,int>> v;
    string s="";
    for(int i=1;i<=t;i++){
        cin>>p>>w;
        v.push_back({q,q+p-1});
        s+=w;
        q+=p;
    }
    long long l=0,r=t-1;
    while(l<=r){
        int ls=v[l].second-v[l].first+1,rs=v[r].second-v[r].first+1;
        if(s[l]!=s[r]) ans+=min(ls,rs);
        if(ls==rs) l++,r--;
        else if(ls>rs) r--,v[l]={v[l].first+rs,v[l].second};
        else l++,v[r]={v[r].first,v[r].second-ls};
    }
    cout<<ans;
    return 0;
}
