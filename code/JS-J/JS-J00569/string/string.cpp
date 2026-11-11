#include<bits/stdc++.h>
using namespace std;
long long a[100000001];
char b[100000001];
char hw[100000001];
char dhw[100000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,sz=1,ans=0,aan=0,w=1,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            hw[w]=b[i];
            aan++;
            w++;
        }
    }
    w=1;
    for(int i=aan;i>=1;i--){
        if(hw[i]!=hw[w]){
            ans++;
        }
        w++;
    }
    cout<<ans/2;
    return 0;
}
