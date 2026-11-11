#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n = 0;
    cin >> n;
    string str;
    long long zong = 0;
    long long num = 0;
    for( int i = 1; i <= n ; i++){
        long long k = 0;
        char n;
        cin >> k;
        cin >> n;
        for( int i = 1 ; i <= k ; i++ ){
            str+=n;
        }
        zong += k;
    }
    for( int i = 0 ; i < zong ; i++ ){
        if( i >= zong-1-i ){
            break;
        }
        if( str[i] != str[zong-1-i]){
            num++;
        }
    }
    cout<<num;
    return 0;
}
