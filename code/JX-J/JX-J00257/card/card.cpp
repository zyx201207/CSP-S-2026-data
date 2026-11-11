#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt[N];
int n,m;
void sp(int start){
vector<pair<int,int> > p,p1;
    for(int j=start;j<=n;j++){
        for(auto [x,y]:p){
            if(x==a[j]){
                for(int i=start;i<y;i++)p1.push_back({p[i].first,p[i].second});
                p=p1;
            }
        }
        p.push_back({a[j],j});
    }
    for(auto [x,y]:p){
        cnt[x]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sp(i);
    }
    for(int i=1;i<=m;i++){
    cout<<cnt[i];
    }
    return 0;
}
