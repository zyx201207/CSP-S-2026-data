#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<pair<int,int>,char> p[200010];
set<pair<pair<int,int>,char> > s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cur=1;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x>>p[i].second;
        p[i].first={cur,cur+x-1};
        cur+=x;
    }
    cur--;
    int mid=cur/2ll;
    for(int i=0;i<n;i++){
        s.insert({{p[i].first.first,0ll},p[i].second});
        if(p[i].first.second>=mid){
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        pair<pair<int,int>,char> temp=p[i];
        temp.first.first=cur-p[i].first.second+1;
        temp.first.second=cur-p[i].first.first+1;
        s.insert({{temp.first.first,1ll},temp.second});
        if(temp.first.second>=mid){
            break;
        }
    }
    int ans=0,l=1;
    char a='?',b='?';
    for(auto x:s){
        int pos=x.first.first,be=x.first.second;
        char ch=x.second;
        if(a=='?'&&be==0){
            a=ch;
            continue;
        }
        if(b=='?'&&be==1){
            b=ch;
            continue;
        }
        if(a!=b){
            ans+=(pos-l);
        }
        if(be==0){
            a=ch;
        }
        if(be==1){
            b=ch;
        }
        l=pos;
    }
    if(a!=b){
        ans+=mid-l+1;
    }
    cout<<ans<<endl;
}
