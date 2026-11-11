#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],s[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
       cin>>a[i];
    }
    int w = 1;
    for(int i = 1;i<=n;i++){
        if(a[i]>=s[1]){
            w = i;
            s[1]=a[i];
        }
    }
    a[w]=0;
    for(int i = 2;i<=m;i++){
            w = 0;
        for(int j = 1;j<=n;j++){
            if(s[i-1]&a[j]>s[i]){
                s[i] = s[i-1]&a[j];
                w = j;
            }
        }
        a[w]=0;
    }
    cout<<s[m];
    return 0;
}
