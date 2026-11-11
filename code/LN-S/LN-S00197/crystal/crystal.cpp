#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int c;
int cmp(int a,int b){
    if(a<=c and b<=c){
        return abs(c-a)<abs(c-b);
    }
    else if(a<=c and b>c) return a;
    else return a<b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    c=s/n;
    int ans=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(m>=abs(c-a[i])){
            ans++;
            m-=abs(c-a[i]);
        }
    }
    cout<<ans;
    return 0;
}
