#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("card.in","r",stdin)
#define F2 freopen("card.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n,m,a[500000+100],ans[300000+100],endsee[500000+100];
void game(int k){
    for(int i=k;i<=n;i++){
        ans[a[i]]++;
        i=endsee[a[i]];
    }
}
int main(){
    F1;F2;
    io();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        endsee[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        game(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
