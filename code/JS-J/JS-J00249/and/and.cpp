#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int a[N],cnt[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int nmax=0,ans=0;
    for(int i=1;i<=N;i++){
        if(cnt[i]>=nmax){
            nmax=cnt[i];
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
