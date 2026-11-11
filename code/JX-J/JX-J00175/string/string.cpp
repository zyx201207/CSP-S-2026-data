#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,sun = 1,m=1;
    cin >> n;
    int a[200005];
    string c;
    string s;
    for(int i= 1;i<=n;i++){
        cin >> a[i]>> s[i];
    }
    for(int j = 1; j <= n; j ++){
        for(int i = sun;i <= a[i];i ++){
            c[i]= s[m];
            m+=1;
    }}
    for(int i= 1; i<=5;i++)
        cout << c[i];
    cout << 2;
    return 0;
}

