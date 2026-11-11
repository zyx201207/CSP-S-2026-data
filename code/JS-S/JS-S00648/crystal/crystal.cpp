#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],maxx=1,j=1;
__int128 now;
long long m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        now+=1LL*(i-j)*(a[i]-a[i-1]);
        while(now>m){
            now-=a[i]-a[j];
            j++;
        }
        maxx=max(maxx,i-j+1);
    }
    cout<<maxx;
    return 0;
}
