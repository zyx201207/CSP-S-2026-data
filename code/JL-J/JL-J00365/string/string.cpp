#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        string q;
        cin >> q;
        for(int j=1;j<=x;j++){
            s+=q;

        }
    }
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]) cnt++;
    }
    cout << cnt;
    //cout << s;
    return 0;
}
