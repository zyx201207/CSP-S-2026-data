/*
till now,i expect 242pts --10:15
how to produce a log here?
O(n^2*m) seems ez
expected 48
---
11:51
expected(totally) at least 204pts nonono
at most [294,302] pts
nonono
i have no j1
r.I.p
---
i give up
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>a(n);
    unordered_map<int,int>cnt;
    for(auto&_:a)cin>>_;
    int s=0;
    while(s!=n){
        vector<int>t;t.reserve(n);
        unordered_map<int,bool>ex;
        unordered_map<int,int>far;
        for(int i=s;i<n;i++){
            int now=a[i];
            if(ex[now]){
                ex[now]=0;
                t.erase(t.begin()+far[now],t.end());
                far.clear();
                ex.clear();
                for(int j=0;j<t.size();j++)far[t[j]]=j+1,ex[t[j]]=1;
            }else{
                if(ex[now]==0)far[now]=t.size()+1;
                t.push_back(now);
                ex[now]=1;
            }
            //for(int j:t)cout<<j<<' ';
            //cout<<'\n';
        }
        for(int i:t)cnt[i]++;
        s++;
        //cout<<'\n';
    }
    unordered_map<int,bool>has;
    for(int i:a)if(!has[i])has[i]=1;
    int c=0;
    for(int i=1;i<=300000;i++){
        if(has[i])
            cout<<cnt[i]<<' ',c++;
        if(c==m)break;
    }
}
