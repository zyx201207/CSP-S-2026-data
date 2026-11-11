#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int eand(int a,int b){
    string s;
    int x=0;
    while(a>0&&b>0){
        if(a%2==1&&b%2==1){
            s += '1';
        }else{
            s += '0';
        }
        a/=2;
        b/=2;
    }
    for(int i = s.size()-1;i>=0;i--){
        x = x*2+s[i]-'0';
    }
    return x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    if(m==1){
        for(int i =1;i<=n;i++){
            ans = max(ans,a[i]);
        }
    }else if(m==n){
        ans = a[1];
        for(int i = 2;i <= n;i++){
            ans = eand(ans,a[i]);
        }
    }
    cout << ans;
    return 0;
}
