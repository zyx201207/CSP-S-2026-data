#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        ans = 1;
        else(){
            ans = 0;
        }
        a = s1[0];
        b = s2[0];
        if(a == b){
            ans = 1;
        else(){
            ans = 0;
            x = s1[1];
            y = s2[2];
            if(x == y){
                ans = 0;
            }
        }
        count << ans;
        }
    }
    return 0;
}
