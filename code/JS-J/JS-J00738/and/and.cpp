#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[200005],cnt2[40];
vector <int> cnt[40];
long long ans;
long long qp(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1) res=res*x;
        y>>=1,x=x*x;
    }
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=a[i];
        int c=0;
        while(x){
            if(x&1) cnt[c].push_back(a[i]);
            c++,x>>=1;
        }
    }
    int i;
    for(i=31;i>=0;i--){
        if(cnt[i].size()>=m){
            break;
        }
    }
    sort(cnt[i].begin(),cnt[i].end());
    for(int j=cnt[i].size()-1;j>=cnt[i].size()-m;j--){
        x=cnt[i][j];
        int c=0;
        while(x){
            if(x&1) cnt2[c]++;
            c++,x>>=1;
        }
    }
    for(int i=0;i<=31;i++){
        if(cnt2[i]>=m) ans+=qp(2,i);
    }
    cout<<ans;
    return 0;
}
