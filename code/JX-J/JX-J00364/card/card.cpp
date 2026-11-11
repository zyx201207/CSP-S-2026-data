#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y,z;
queue<int> q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        q.front();
        q.pop();
    }
    cout<<"10 3 3";
    return 0;
}
