#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<set<int>>ans(n);
    for(int i=0;i<n;i++){
        deque<int>q;
        for(int j=i;j<n;j++){
            for(auto x:q){
                if(x==a[j]){
                    while(!q.empty()&&q.back()!=a[j]){
                        q.pop_back();
                    }
                    q.push_back(a[j]);
                    continue;
                }
            }
            q.push_back(a[j]);
        }
        for(auto x:q)ans[i].insert(x);
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=(ans[i].find(i)!=ans[i].end());
        }
        cout<<cnt<<' ';
    }
    return 0;
}
//zhe bu jiu shi tuo wu gui ma
//zhe suan shi ad-hoc ma
//wo hao xiang mei shi jian xie zhe ti le
//

//nen bu nen shang mi huo xin wei da shang QWQ

//X X XXX
//       --Xterfusion

//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//  freopen
//ni bu hui yi wei wo zhu shi freopen le ba

//bing bing bing
//↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑! ↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ 
//↑↑↑~~~ ↑↑↑~~~ ↑↑↑~~~ ↑~~~~~~~~~~~~~~
//↑ ↑ ↑↑↑ ↑↑ ↑↑ ↑↑ ↑↑↑
//a a ai ai a e oo o a a e o i o a a aa aa aa
//xxx xx xx xxxxx
//↑ ↑ ↑ ↑~~~~~~~~~~

//shen mi zi mu ya
//- -
//-  -
//- -
//- -
//-  -
//-   -

//  ||- ||
//  || -||
//  ||- ||
//  || -||
//  ||- ||
//  || -||
//  ||- ||
//  || -||
//  ||- ||
//  || -||
//  ||- ||
//  || -||

// =||  ||=
//= ||  || =
//= ||  || =
//= ||  || =
//= ||  || =
// =||  ||=

//~~ta zheng de heng xi huan mo wang qu~~