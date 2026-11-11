#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],ans[N],anss=0;
bool cnt(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cnt);
    cout<<a[m];
    return 0;
}
