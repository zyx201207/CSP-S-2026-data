#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,cnt=1;
char a[2147471579];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a1;
        char c1;
        cin>>a1>>c1;
        for(int j=1;j<=a1;j++){
            a[cnt]=c1;
            cnt++;
        }
    }
    for(int i=1;i<=cnt/2;i++)
        if(a[i]!=a[cnt-i])
            ans++;
    cout<<ans;
    return 0;
}
