#include <bits/stdc++.h>
using namespace std;

long long n;
string s = "";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >>n;
    for(long long i = 1 ; i <= n ; i++){
        int p;
        char q;
        cin >>p>>q;
        for(long long _ = 0 ; _ < p ; _++) s += q;
    }
    //cout <<s<<'\n';

    long long r = s.size(),k = 0;
    //for(int i = 1 ; i <= s.size();i++) cout <<s[i];
    for(long long l = 0 ; l < r ; l++){
        r--;
        if(s[l] != s[r]){
            //cout <<s[l]<<' '<<s[r]<<'\n';
            k++;
        }
    }

    cout <<k;

    return 0;
}
