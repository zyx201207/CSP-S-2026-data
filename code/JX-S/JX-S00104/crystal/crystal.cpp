#include <bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
long long n,m;
long long c[maxn];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n,cmp);
    int near=c[n/2];
    int ans=1;
    int cur=n/2-1;
    while(m--){
        if(cur==-1){
            break;
        }
        c[cur]++;
        if(c[cur]==near) {
            ans++;
            cur--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
