#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll a[N],d[N];
ll m=0;
int n;
void init(){
    d[0]=0;
    for(int i=1;i<=n;++i){
        d[i]=d[i-1]+a[i];
    }
}
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    init();
    for(int i=0;i<n;++i){
        if(m>=(i*a[i+1]-d[i]) && m<((i+1)*a[i+2]-d[i+1])){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    return 0;
}
