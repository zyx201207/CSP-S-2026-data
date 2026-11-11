#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a,c[2000010];
    int n,m,ans,l=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        for(int j=1;j<=m;j++){
            c[j+l]=a;
        }
        l+=m;
    }
    for(int i=1;i<=l/2;i++){
        if(c[i]!=c[l-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
