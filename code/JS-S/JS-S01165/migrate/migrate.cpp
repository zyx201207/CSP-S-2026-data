#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t;
int n,d,a[N];
void init(){
    n=0,d=0;
    memset(a,0,sizeof a);
}
int main(){
    freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        init();
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<n-(d+1)<<"\n";
    }
    return 0;
}

