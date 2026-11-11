#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+6;
int w[maxn];
void dj(int x,int y){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
cout<<1<<'\n'

}
int main(){
//freopen("subway.in","r",stdin);
//freopen("subway.out","w",stdout);
int c,n,m,d,q;
cin>>c>>n>>m>>d>>q;
vector<pair<int,int>> a[n+1];
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++){
    int road;
    cin>>road;
    for(int j=1;j<=road;j++){
       int to;
       ll wor;
       cin>>to>>wor;
        a[i].push_back({to,wor});
        a[to].push_back({i,wor});
    }
}
while(q--){
    int a,b;
    cin>>a>>b;
    dj(a,b);
    cout<<ans;
}
return 0;
}
