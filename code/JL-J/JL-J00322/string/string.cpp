#include <bits/stdc++.h>
using namespace std;

int a[100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a,c,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        a[m]=2*a[c];
    }
    cout<<a;
    return 0;
}
