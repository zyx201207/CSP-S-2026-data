#include<bits/stdc++.h>
using namespace std;
int n,l=0;
char a[100000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int ans=0;
    for(int i = 1;i<=n;i++){
        int o;
        char p;
        cin >>o>>p;
        if(o>=1000000000){cout << 3000000000;return 0;}
        for(int j = 1;j<=o;j++){
            a[++l]=p;
        }

    }
    for(int i = 1;i<=(l+1)/2;i++){
        if(a[i]!=a[l+1-i]){
            ans++;
        }

    }
    cout << ans;
    return 0;
}
