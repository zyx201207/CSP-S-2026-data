#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
int t[1000010];
vector<int> a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a.resize(n);
    for(auto &i:a) cin>>i;
    for(int i=1;i<=m;i++){
        list<int> n;
        map<int,list<int>::iterator> mp;
        for(auto j=a.begin()+i;j!=a.end();j++){
            if(mp.find(*j)!=mp.end()) n.erase(mp[*j],n.end());
            n.push_back(*j);
            auto c=n.end(); c--;
            mp[*j]=c;
        }
        for(auto f:n) t[f]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]+1<<" ";
    cout<<endl;
}

