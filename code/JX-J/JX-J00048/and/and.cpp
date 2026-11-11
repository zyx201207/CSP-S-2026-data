#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;cin>>n>>m;
    vector<int> a;
    int mkk=((1<<30)-1);
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        a.push_back(tmp);
    }
    vector<vector<int> > dcl;
    int y=-1;
    for(int i=1;i<((1<<a.size())-1);i++){
        if(__builtin_popcount(i)==m){
            vector<int> ttt;
            for(int j=0;(1<<j)<=i;j++){
                if((1<<j)&i){
                    ttt.push_back(a[j]);
                }
            }
            dcl.push_back(ttt);
        }
    }
    for(int i=0;i<dcl.size();i++){
        int kkk=mkk;
        for(int j=0;j<m;j++){
            kkk = (kkk&dcl[i][j]);
        }
        ans=max(ans,kkk);
    }
    cout<<ans;
    return 0;
}
