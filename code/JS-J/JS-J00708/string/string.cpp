#include <bits/stdc++.h>
using namespace std;

long long sz[200022];
char c1[200022], c2[200022];
long long s1[200022], s2[200022];

int main(){
    //warning:don't forget to use long long
    //9:26:20 first finish (all tasks accepted)
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> sz[i] >> c1[i];
        s1[i] = s1[i - 1] + sz[i];
    }
    for(int i = 1;i <= n;i++){
        s2[i] = s2[i - 1] + sz[n - i + 1];
        c2[i] = c1[n - i + 1];
    }
    long long p1 = 1, p2 = 1, ans = 0;
    while(p1 <= n && p2 <= n){
        if(s1[p1] == s2[p2]){
             if(c1[p1] != c2[p2]){
                ans += s1[p1] - max(s1[p1 - 1], s2[p2 - 1]);
             }
             p1++;
        }
        else if(s1[p1] < s2[p2]){
             if(c1[p1] != c2[p2]){
                ans += s1[p1] - max(s1[p1 - 1], s2[p2 - 1]);
             }
             p1++;
        }
        else{
            if(c1[p1] != c2[p2]){
                ans += s2[p2] - max(s1[p1 - 1], s2[p2 - 1]);
            }
            p2++;
        }
    }
    //cout << ans << "\n";
    cout << ans / 2 << "\n";
}
//aabbcaac
//caacbbaa
//aaabbbaaaaccaaabc
//cbaaaccaaaabbbaaa
//abbcccba
//abcccbba
//aaaaaaaaaaaabc
//cbaaaaaaaaaaaa
