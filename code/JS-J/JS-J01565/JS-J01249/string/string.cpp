#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s = "";
    int x;
    char c;
    for(int i = 1;i <= n;i++){
        cin >> x >> c;
        for(int j = 1;j <= x;j++){
            s += c;
        }
    }
    int t = s.length();
    int mid;
    if(!(t & 1)){
        int mid = t / 2;
        string s1,s2;
        s1 = s.substr(0,mid);
        s2 = s.substr(mid,mid + 1);
        reverse(s2.begin(),s2.end());
        long long diff = 0;
        for(int i = 0;i < s1.length();i++){
            if(s1[i] != s2[i]) diff ++ ;
        }
        cout << diff << '\n';

    } else {
        int mid = t / 2;
        string s1,s2;
        s1 = s.substr(0,mid);
        s2 = s.substr(mid + 1,mid);
        reverse(s2.begin(),s2.end());
        long long diff = 0;
        for(int i = 0;i < s1.length();i++){
            if(s1[i] != s2[i]) diff ++ ;
        }
        cout << diff << '\n';
    }
    return 0;
}
