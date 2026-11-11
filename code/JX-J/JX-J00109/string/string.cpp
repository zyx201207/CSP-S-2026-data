#include <bits/stdc++.h>
using namespace std;
int n,s,d;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>a[i]>>c[i];
        s+=a[i];
    }
    d=s;
    for (int i=1;i<=n;i++){
        d-=a[i];
        if (d<=s/2){
            if (c[i]!=c[i-1]){
                cout <<s/2;
                return 0;
            }
        }
    }
    cout <<"0";
    return 0;
}
