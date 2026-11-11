#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    int a;
    char k;
    for (int i=0;i<n;i++){
        cin >> a >> k;
        for (int j=0;j<a;j++){
            s+=k;
        }
    }
    string st=s;
    reverse(s.begin(),s.end());
    long long sum=0;
    for (int i=0;i<s.length();i++){
        if (s[i]!=st[i]) sum++;
    }
    cout << sum/2;
    return 0;
}
