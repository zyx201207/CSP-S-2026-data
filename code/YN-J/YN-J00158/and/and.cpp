#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
 int n,m,a,cnt,ans,num;
 bool ok[N][35];
 vector<int>idx,del;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a;
        for(int j=30;j>=0;--j)ok[i][j]=(a>>j)&1;
    }
    for(int j=30;j>=0;--j){
        cnt=0;idx.clear();
        for(int i=1;i<=n;++i)if(ok[i][j])cnt++,idx.push_back(i);
        if(cnt>=m){ans|=1<<j;num=j-1;break;}
    }
    if(num<0){cout<<ans;return 0;}
    for(int j=num;j>=0;--j){
        del.clear();cnt=0;
        for(int v:idx){if(ok[v][j])cnt++;else del.push_back(v);}
        if(cnt>=m){ans|=1<<j;for(int d:del)idx.erase(lower_bound(idx.begin(),idx.end(),d));}
        if(idx.size()<m)break;
    }
    cout<<ans;return 0;
}
/*
4 2
3 15 12 12
0011 1111 1100 1100
*/
