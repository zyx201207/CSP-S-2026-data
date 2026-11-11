#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int pan[6];
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        pan[0] = 1;
    }
    else{
        pan[0] = 0;
    }
    if(pan[0] == 1 && s1[0] == s2[0] && s1[1] == s2[1]){
        pan[1] = 1;
    }
    else{
        pan[1] = 0;
    }
    if(pan[1] == 1){
        if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
            pan[2] = 1;
        }
        else{
            pan[2] = 0;
        }
    }
    else{
        pan[2] = 0;
    }
    if(pan[2] == 1){
        if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1){
            pan[3] = 1;
        }
        else{
            pan[3] = 0;
        }
    }
    else{
        pan[3] = 0;
    }
    for(int i = 0;i < 4;i++){
        cout << pan[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
