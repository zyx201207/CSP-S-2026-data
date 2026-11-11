#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long maxx=-1,minx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        minx=max(minx,a[i]);
        if(minx!=maxx){
            minx=min(minx,maxx);
        }
    }
    cout<<minx;
    return 0;
}

