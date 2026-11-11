#include <bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        ans1 = 1;
    }
    if(ans1 == 1 && s1[0] == s2[0] & s1[1] == s2[1]){
        ans2 = 1;
    }
    if(s1[2] == 'D'|| s1[2] == 'F'){
        c1 = 1;
    }
    if(s2[2] == 'D' || s1[2] == 'F'){
        c2 = 1;
    }
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
        c1 = 2;
    }
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
        c2 = 2;
    }
    if(ans2 == 1 && c1 == c2){
        ans3 = 1;
    }
    if(ans3 == 1 && (s1[2] == 'D' || s1[2] == 'F')){
        ans4 = 1;
    }
    if(ans3 == 1 && (s1[2] == 'B' || s2[2] == 'B')){
        ans4 = 1;
    }
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
