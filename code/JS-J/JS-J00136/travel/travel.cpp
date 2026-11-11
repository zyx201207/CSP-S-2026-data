#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int a[4] = {0,0,0,0};
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        a[0] = 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            a[1] = 1;
            char ch1 = s1[2];
            char ch2 = s2[2];
            if((ch1 == 'F' && ch2 == 'D') || (ch1 == 'D' && ch2 == 'F')||(ch1 != 'F' && ch2 != 'D'&& ch1!= 'D' && ch2 != 'F')){
                a[2] = 1;
                if(ch1 - ch2 == 1 || ch2 - ch1 == 1){
                    a[3] = 1;
                }
            }
        }
    }
    for(int i = 0;i < 4;i++){
        cout << a[i];
    }
    return 0;
}
