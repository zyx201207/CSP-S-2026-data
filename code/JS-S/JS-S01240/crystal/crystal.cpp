#include<bits/stdc++.h>
using namespace std;
long long s[500005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,depth = 0;
    int ans = 1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++){
        depth = 0;
        for(int j=i-1;j>=1;j--){
            depth+=s[i]-s[j];
            if(depth<=m){
                ans = max(ans,i-j+1);
            }
            else{
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
