#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005];
long long b[200005];
long long ant = 0;
string s;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> b[i] >> a[i];
        s.insert(s.size(),b[i],a[i]);
    }

    long long d = s.length() / 2;
    long long w = s.length() - 1;
    for(long long i = 0;i < d;i++){
        if(s[i] != s[w-i]){
            ant++;
        }
    }

    cout << ant;
    return 0;
}
