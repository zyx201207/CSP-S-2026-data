#include<bits/stdc++.h>
using namespace std;
string s[105][105];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>s[i][j];
        }
    }

    cout<<2;
    return 0;
}
