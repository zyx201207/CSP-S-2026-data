#include<bits/stdc++.h>
using namespace std;
string s;
long long n , a , ans = 0;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> c;
        for(int i = 0 ; i < a ; i++){
            s += c;
        }
    }
    for(int l = 0 , r = s.size()-1 ; l <= r ; l++ , r--){
        if(s[l] != s[r])ans++;
    }
    cout << ans;
return 0;
}

