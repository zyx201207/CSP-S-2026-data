#include<bits/stdc++.h>
using namespace std;
int a[200010];
set<int> b;
int n,m;
bool flag[300030];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!flag[a[i]]){
            b.insert(i);
            flag[a[i]]=1;
        }
    }
    for(auto v:b){
        cout<<(rand()%n+rand()%n)%n+1<<" ";
    }

    return 0;
}
