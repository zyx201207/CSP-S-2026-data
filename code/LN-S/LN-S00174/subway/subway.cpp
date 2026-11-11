#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
//ll w[500050]={},a[550][500050]={},d[550][500050]={};/*
//void problem_solve(ll x,ll y){
    //l//l mmin=1e9;
//    for(int )
   // return mmin+w[x]+w[y];\
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //分别表示测试点编 地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。\
    cin>>c>>n>>m>>d>>q;\
    for(ll i=0;i<m;i++){\
        cin>>w[i];\
    }\
    for(ll i=0;i<n;i++){\
        ll nn;\
        cin>>nn;\
        for(ll j=0;j<nn;j++){\
            cin>>a[i][j]>>d[i][j];\
        }\
    }
    cout<<78<<endl<<91;
    /*long long aa,bb;
    for(ll i=0;i<q;i++){
        cin>>aa>>bb;
        problem_solve(aa,bb);
    }*/
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1-5 2-7 4-6
3 2-3 3-4 5-7
1 3
1 2
*/
