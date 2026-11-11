#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];s[a[i]]++;
    }
    int x=s[1];
    for(int i=1;i<=m;i++){
        cout<<x<<" ";
        x+=s[i+1];
    }
    return 0;
}
