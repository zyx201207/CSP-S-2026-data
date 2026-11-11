#include <bits/stdc++.h>
using namespace std;

int s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int ans=0;
    if(m==1){
        for(int i=1;i<=n;i++){
            if(s[i]>ans) ans=s[i];
        }
    }
    cout<<ans;
    return 0;
}
