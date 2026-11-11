#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q = 0;
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        q++;
        if((s1[0]==s2[0])&&(s1[1] == s2[1])){
            q++;
            if((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2] >='D' && s2[2] >= 'D')){
                q++;
                if(int(s1[2])+1 == (int(s2[2]))) q++;
                else if(int(s1[2])-1 == (int(s2[2]))) q++;
            }
        }
    }
    if(q == 1) cout <<"1000";
    if(q == 2) cout <<"1100";
    if(q == 3) cout <<"1110";
    if(q == 4) cout <<"1111";
    if(q == 0) cout <<"0000";
    return 0;
}
