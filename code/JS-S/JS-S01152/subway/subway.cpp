#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
vector<int> w,k;
vector<vector<int> > a,t,t1;
bool vis[100005];
int dfs(int p,int cost){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int wi;
        cin>>wi;
        w.push_back(wi);
    }
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        vector<int> ai,ti;
        k.push_back(ki);
        for(int j=1;j<=ki;j++){
            int aii,tii;
            cin>>aii>>tii;
            ai.push_back(aii);
            ti.push_back(tii);
        }
        a.push_back(ai);
        t.push_back(ti);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
    }
    return 0;
}
/*
写不动了。。。
我要打wotb&df
明年在来吧。。。





dzd我喜欢你很久了！！！！！！





游记：
（写了一段游记，只有聪明人能看见，你看见了么）
🚾🚾🚾🚾🚾🚾🚾🚾🚾🚾🚾🚾
*/
