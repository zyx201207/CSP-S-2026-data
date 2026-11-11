#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 5*1e5+5;
int a[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int now = a[1],cnt = 0,res = 1;
    for(int i = 2;i<=n;i++){
        now+=a[i];
        cnt = (now+m)/i;
        if(cnt<a[i])continue;
        res = i;
    }
    cout<<res;
    return 0;
}
