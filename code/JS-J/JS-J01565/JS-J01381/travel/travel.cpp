#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char sit1 = s1[2],sit2 = s2[2];
    ll a = stoll(s1.substr(0,2)),b = stoll(s2.substr(0,2));
    cout << (c1 == c2);
    if(c1 != c2){
        cout << 0 << 0 << 0;
        return 0;
    }
    if(a == b){
        cout << 1;
        if(sit1 == 'A'){
            cout << (sit2 == 'B' || sit2 == 'C');
            cout << (sit2 == 'B');
        }
        if(sit1 == 'B'){
            cout << (sit2 == 'A' || sit2 == 'C');
            cout << (sit2 == 'A' || sit2 == 'C');
        }
        if(sit1 == 'C'){
            cout << (sit2 == 'B' || sit2 == 'A');
            cout << (sit2 == 'B');
        }
        if(sit1 == 'D'){
            cout << (sit2 == 'F');
            cout << (sit2 == 'F');
        }
        if(sit1 == 'F'){
            cout << (sit2 == 'D');
            cout << (sit2 == 'D');
        }
    }else{
        cout << 0 << 0 << 0;
    }
    return 0;
}