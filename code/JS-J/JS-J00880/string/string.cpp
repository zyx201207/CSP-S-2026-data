#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010],nu[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=cnt+1;j<=cnt+a[i];j++){
            nu[j]=c[i];
        }
        cnt+=a[i];
    }
    for(int i=cnt/2;i>=1;i--){
        if(nu[i]!=nu[cnt-i+1]){
            ans++;
        }
    }cout<<ans;
    return 0;
}
