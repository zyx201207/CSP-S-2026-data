#include <bits/stdc++.h>
#include <cstring>
using namespace std;

string c1, s1, c2, s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    string s = "0000";
    for(int i; i <= s.size(); i++){
        if(c1 == c2){
            s[0] = 1;
        }
        if(s1[1] == s2[1]){
            s[1] = 1;
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
