#include <bits/stdc++.h>
using namespace std;
const long long LLINT=0x3f3f3f3f3f3f3f3f3f;
long long m,a[50020];
long long  n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long cnt = 0,r;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long it=1;it<=n;it++){
        for(long long i=1;i<it;i++){
            cnt = cnt+a[it]-a[i];
        }
        if(cnt<=m){
            r = it;
        }
        cnt = 0;
    }
    cout<<r;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
