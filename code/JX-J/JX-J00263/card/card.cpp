#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
long long a[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0;
    for(int i=0;i<n;i++){
        int r=l+i-1;
        if(a[i]==0){
            a[i]=r;
            a[++ans];
        }else{
            a[i]=0;
            a[++ans];
        }

    }
    for(int i=1;i<=m;i++){
        cout<<ans<<" ";
    }
    return 0;
}
