#include <bits/stdc++.h>
using namespace std;
string a[1000005],l[1000005];
int main() {
    freopen("string.in","l",stdin);
    freopen("string.out","r",stdout);
    long long  n,m,k=0,h=0;
    string d,c,b;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m >> c;
        k += m;
        for(int j=1;j<=m;j++){
            d += c;
        }
    }
    for(int i=0;i<k;i++){
        a[i] = d[i];
    }
    for(int i=0;i<k;i++){
        l[i] = a[k-1-i];
    }
    for(int i=0;i<=k;i++){
        if(l[i] != a[i]){
            l[i] = a[i];
            h +=1;
        }
        else{
            cout << h;
            break;
        }
    }

    return 0;
}
