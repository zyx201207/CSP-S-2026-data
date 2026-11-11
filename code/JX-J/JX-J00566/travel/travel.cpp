#include<bits/stdc++.h>
using namespace std;

int res[5] = {0,0,0,0};
string inp[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>inp[0]>>inp[1]>>inp[2]>>inp[3];

    if(inp[0] == inp[2]){
        res[0] = 1;
        if(inp[1][0] == inp[3][0] && inp[1][1] == inp[3][1]){
            res[1] = 1;
            if((inp[1][2] == 'D' || inp[1][2] == 'F') && (inp[3][2] == 'D' || inp[3][2] == 'F')){
                res[2] = 1;
                res[3] = 1;
            }
            if((inp[1][2] == 'A' || inp[1][2] == 'B'|| inp[1][2] == 'C') && (inp[3][2] == 'A' || inp[3][2] == 'B'|| inp[3][2] == 'C')){
                res[2] = 1;
                if(!(inp[1][2] == 'A' && inp[3][2] == 'C')){
                    if(!(inp[3][2] == 'A' && inp[1][2] == 'C')){
                        res[3] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0;i<4;i++) cout<<res[i];


    fclose(stdin);
    fclose(stdout);
    return 0;
}
