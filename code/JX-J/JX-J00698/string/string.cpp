#include <bits/stdc++.h>
using namespace std;
string z='abcdefghijklmnopqrstuvwxyz';
long long n,b,l=0,a[20000000];
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b;
        cin>>c;
        for(int j=1;j<=n;j++){
            a[j]=z[c];
        }
    }
    return 0;
}
