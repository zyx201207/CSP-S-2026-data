#include <bits/stdc++.h>
using namespace std;

int a[200010];
bool b[200010];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!b[j]){
                if((a[j]>>i)&1){
                    cnt++;
                }
            }
        }
        if(cnt>=m){
            ans+=1<<i;
            for(int j=1;j<=n;j++){
                if(!((a[j]>>i)&1)){
                    b[j]=true;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
