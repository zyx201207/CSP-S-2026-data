#include <bits/stdc++.h>
using namespace std;
const int N=2e9+10;
int n,q;
char ch;
char a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int idx=0;
    for (int i=1;i<=n;i++){
        cin>>q>>ch;
        for (int j=1;j<=q;j++){
            a[++idx]=ch;
        }
    }
    if(n==1)cout<<0;
    int ans=0;
    for (int i=1;i<=idx/2;i++){
        if(a[i]!=a[idx-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}