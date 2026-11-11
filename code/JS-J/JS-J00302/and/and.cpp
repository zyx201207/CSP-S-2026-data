#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,shu0=0;
    cin>>n>>m;
    cin>>a[1];
    long long cnt=a[1];
    long long maxx=a[1];
    for(long long i=2;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        b[a[i]]++;
        cnt=cnt&a[i];
    }
    if(n==1||m==1){
        cout<<maxx;
        return 0;
    }
    if(n==m){
        cout<<cnt;
        return 0;
    }
    if(m==2){
        long long maxn=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    int ci=0;
    for(int i=maxx;i>=0;i--){
        if(b[i]!=0)ci++;
        if(ci==m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
