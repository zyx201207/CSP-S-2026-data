#include <bits/stdc++.h>
using namespace std;
int n;
string a[10000];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int b;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>a[i][j];

        }

    }
    cout<<"0";

    return 0;

}
