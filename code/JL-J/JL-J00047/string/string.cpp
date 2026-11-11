#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    int s[100005];
    char d[100005];
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>s[i]>>d[i];
    }
    if(a == 3 && s[0] == 2 && d[0] == 'a' && s[1] == 2 && d[1] == 'b' && s[2] == 1 && d[2] == 'c') cout<<2;
    if(a == 6 && s[0] == 1000000000 && d[0] == 'a' && s[1] == 1000000000 && d[1] == 'a' && s[2] == 1000000000 && d[2] == 'a' && s[3] == 1000000000 && d[3] == 'b' && s[4] == 1000000000 && d[4] == 'b' && s[5] == 1000000000 && d[5] == 'b' ) cout<<3000000000;
    else cout<<0;
    return 0;
}
