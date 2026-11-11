#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
map <int,int>mp;
map<int,int>::iterator it;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->second<<" ";
    }
    return 0;
}
