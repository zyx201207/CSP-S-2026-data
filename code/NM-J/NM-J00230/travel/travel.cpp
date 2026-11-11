#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int la,lc,ll,ZZ[5] = {0};
    string lb,ld;
    cin >> la >> lb >> lc >> ld;

    if (la == lc){
        ZZ[0] = 1;
    }
    else{
        ZZ[0] = 0;
    }
    if(lb[0] == ld[0] && lb[1] == ld[1]){
        ZZ[1] = 1;
    }
    else{
        ZZ[1] = 0;
    }
    if (lb[2] == 'A' || lb[2] == 'B' || lb[2] == 'C'){
        ll = 0;
    }
    else{
        ll = 1;
    }
    if (ll == 0){
        if(ld[2] == 'A' || ld[2] == 'B' || ld[2] == 'C'){
            ZZ[2] = 1;
        }else{
            ZZ[2] = 0;
        }
    }
    if (ll == 1){
        if(ld[2] == 'D' || ld[2] == 'F'){
            ZZ[2] = 1;
        }else{
            ZZ[2] = 0;
        }
    }
    if (lb[2] == 'A'){

        if(ld[2] == 'B'){
            ZZ[3] = 1;
        }else{
            ZZ[3] = 0;
        }
    }
    if (lb[2] == 'B'){

        if(ld[2] == 'C'){
            ZZ[3] = 1;
        }
        else if(ld[2] == 'A'){
            ZZ[3] = 1;
        }
        else{
            ZZ[3] = 0;
        }
    }

    if (lb[2] == 'C'){
        if(ld[2] == 'B'){
            ZZ[3] = 1;
        }
        else{
            ZZ[3] = 0;
        }
    }
    if (lb[2] == 'D'){
        if(ld[2] == 'F'){
            ZZ[3] = 1;
        }
        else{
            ZZ[3] = 0;
        }
    }
    if (lb[2] == 'F'){

        if(ld[2] == 'D'){
            ZZ[3] = 1;
        }
        else{
            ZZ[3] = 0;
        }
    }
    for(int i = 0;i < 4;i++){
        if(i == 0){
            cout << ZZ[i];
        }
        else if(ZZ[i-1] == 1){
            cout << ZZ[i];
        }
        else{
            cout << "0";
        }
    }
    return 0;
}

