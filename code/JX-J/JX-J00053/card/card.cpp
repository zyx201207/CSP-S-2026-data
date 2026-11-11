#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
int a[1000005];
int c[1000005];
int ans[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof c);
        for(int j=i-1;j<n;j++){
            c[a[j]]=1;
        }
        for(int j=i-1;j<n;j++){
            if(c[j]) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}
