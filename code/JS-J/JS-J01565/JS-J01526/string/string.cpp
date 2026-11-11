#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin >> n;
    long long a[n+5];
    string s="";
    for (int i=0;i<n;i++){
        int a;
        char c;
        cin >> a >> c;
        string s1(a,c);
        s+=s1;
    }
    cout << s << endl;
    for (int i=0;i<=(n+1)/2;i++){
        if (s[i]!=s[n-1-i])
            cnt++;
    }
    cout << cnt;
    return 0;
}
