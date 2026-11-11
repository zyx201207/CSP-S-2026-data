#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    string s,l;
    long long n;
    long long a,b=0;
    cin >> n;
    long long r=0;
    for(int i=1;i<=n;i++){
        cin >> a;
        cin >> l;
        b+=a;
        for(;r<a+r;r++){
            s[r]=a;
        }
    }
    for(int i=0;i<b;i++){
        if(s[r]==s[b-1-r]){
            cout << 0;
        }
    }
    return 0;
}
